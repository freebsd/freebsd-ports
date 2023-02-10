--- src/3rdparty/chromium/base/threading/thread_task_runner_handle.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/threading/thread_task_runner_handle.cc
@@ -8,6 +8,7 @@
 #include <utility>
 
 #include "base/bind.h"
+#include "base/callback_helpers.h"
 #include "base/check_op.h"
 #include "base/dcheck_is_on.h"
 #include "base/lazy_instance.h"
@@ -40,6 +41,7 @@ const scoped_refptr<SingleThreadTaskRunner>& ThreadTas
   return current->task_runner_;
 }
 
+#if defined(OS_BSD)
 // static
 bool ThreadTaskRunnerHandle::IsSet() {
   return !!thread_task_runner_tls.Pointer()->Get();
@@ -89,6 +91,7 @@ ThreadTaskRunnerHandleOverride::ThreadTaskRunnerHandle
         std::make_unique<ScopedDisallowRunningRunLoop>();
   }
 }
+#endif
 
 ThreadTaskRunnerHandleOverride::~ThreadTaskRunnerHandleOverride() {
   if (task_runner_to_restore_) {
