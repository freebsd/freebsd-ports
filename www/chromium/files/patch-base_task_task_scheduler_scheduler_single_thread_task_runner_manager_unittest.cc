--- base/task/task_scheduler/scheduler_single_thread_task_runner_manager_unittest.cc.orig	2018-12-12 22:56:01.000000000 +0100
+++ base/task/task_scheduler/scheduler_single_thread_task_runner_manager_unittest.cc	2018-12-16 01:43:12.295373000 +0100
@@ -295,6 +295,9 @@
   EXPECT_EQ(ThreadPriority::NORMAL, thread_priority_normal);
 }
 
+#if defined(OS_BSD)
+#define ThreadNamesSet DISABLED_ThreadNamesSet
+#endif
 TEST_P(TaskSchedulerSingleThreadTaskRunnerManagerCommonTest, ThreadNamesSet) {
   constexpr TaskTraits foo_traits = {TaskPriority::BEST_EFFORT,
                                      TaskShutdownBehavior::BLOCK_SHUTDOWN};
