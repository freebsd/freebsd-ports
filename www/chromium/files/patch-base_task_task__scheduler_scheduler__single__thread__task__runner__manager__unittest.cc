--- base/task/task_scheduler/scheduler_single_thread_task_runner_manager_unittest.cc.orig	2019-03-11 22:00:51 UTC
+++ base/task/task_scheduler/scheduler_single_thread_task_runner_manager_unittest.cc
@@ -295,6 +295,9 @@ TEST_P(TaskSchedulerSingleThreadTaskRunnerManagerCommo
   EXPECT_EQ(ThreadPriority::NORMAL, thread_priority_normal);
 }
 
+#if defined(OS_BSD)
+#define ThreadNamesSet DISABLED_ThreadNamesSet
+#endif
 TEST_P(TaskSchedulerSingleThreadTaskRunnerManagerCommonTest, ThreadNamesSet) {
   constexpr TaskTraits foo_traits = {TaskPriority::BEST_EFFORT,
                                      TaskShutdownBehavior::BLOCK_SHUTDOWN};
