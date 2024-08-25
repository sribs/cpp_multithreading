#ifndef TASK_HPP_INCLUDED
#define TASK_HPP_INCLUDED

namespace multithreading
{
        enum class task_type
    {
        ONLY_ONCE,
        FIXED_RATE,
        FIXED_DELAY
    };

    enum class task_state
    {
        ENQUEUED,
        PENDING,
        RUNNABLE,
        EXECUTION,
        COMPLETED,
        DONE
    };

    class Task
    {
    public:

        // task function
        std::function<void ()> task_func;

        // task state
        task_state state;
    };

    class Single_task : task
    {
    public:

        const task_type task_t = task_type.ONLY_ONCE;


    };

    // Generic Task Queue
    //
    class Task_queue
    {
    protected:
        std::priority_queue<Task> jQ;
        std::shared_mutex mtx;

    public:

        // enqueue a new task to the job queue;
        void enqueue(task t);

        // dequeue a new task from the job queue
        task dequeue();

        // get the size of the task;
        size_t size();
    };

    // more sophesticated task queue
    // This queue contains the list of tasks where the
    // workers are waiting to be assigned
    //
    class PendingQueue : public TaskQueue
    {

    };

    // Runnable Queue : We now have workers bound to the task
    // They are waiting for the schedulers to be executed
    //
    class RunnableQueue : public TaskQueue
    {

    };

    // completion Queue : Completed tasks are kept here
    //
    class CompletionQueue : public TaskQueue
    {

    };
}

#endif // TASK_HPP_INCLUDED
