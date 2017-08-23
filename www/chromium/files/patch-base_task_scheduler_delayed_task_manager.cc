--- base/task_scheduler/delayed_task_manager.cc.orig	2017-08-10 23:52:26.912451000 +0200
+++ base/task_scheduler/delayed_task_manager.cc	2017-08-11 00:22:09.125479000 +0200
@@ -70,9 +70,6 @@
     if (started_.IsSet()) {
       AddDelayedTaskNow(std::move(task), delay,
                         std::move(post_task_now_callback));
-    } else {
-      tasks_added_before_start_.push_back(
-          {std::move(task), std::move(post_task_now_callback)});
     }
   }
 }
