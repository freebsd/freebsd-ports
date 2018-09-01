--- base/task_scheduler/scheduler_single_thread_task_runner_manager_unittest.cc.orig	2018-08-31 05:44:39.768079000 +0200
+++ base/task_scheduler/scheduler_single_thread_task_runner_manager_unittest.cc	2018-08-31 05:45:55.842704000 +0200
@@ -301,6 +301,9 @@
   EXPECT_EQ(ThreadPriority::NORMAL, thread_priority_normal);
 }
 
+#if defined(OS_BSD)
+#define ThreadNamesSet DISABLED_ThreadNamesSet
+#endif
 TEST_P(TaskSchedulerSingleThreadTaskRunnerManagerCommonTest, ThreadNamesSet) {
   constexpr TaskTraits foo_traits = {TaskPriority::BACKGROUND,
                                      TaskShutdownBehavior::BLOCK_SHUTDOWN};
