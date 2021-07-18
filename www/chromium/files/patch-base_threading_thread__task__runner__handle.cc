--- base/threading/thread_task_runner_handle.cc.orig	2021-04-14 18:40:48 UTC
+++ base/threading/thread_task_runner_handle.cc
@@ -8,6 +8,7 @@
 #include <utility>
 
 #include "base/bind.h"
+#include "base/callback_helpers.h"
 #include "base/check_op.h"
 #include "base/lazy_instance.h"
 #include "base/run_loop.h"
@@ -33,6 +34,7 @@ const scoped_refptr<SingleThreadTaskRunner>& ThreadTas
   return current->task_runner_;
 }
 
+#if defined(OS_BSD)
 // static
 bool ThreadTaskRunnerHandle::IsSet() {
   return !!thread_task_runner_tls.Pointer()->Get();
@@ -80,6 +82,7 @@ ThreadTaskRunnerHandleOverride::ThreadTaskRunnerHandle
   if (!allow_nested_runloop)
     no_running_during_override_.emplace();
 }
+#endif
 
 ThreadTaskRunnerHandleOverride::~ThreadTaskRunnerHandleOverride() {
   if (task_runner_to_restore_) {
