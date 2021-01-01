--- base/threading/thread_task_runner_handle.cc.orig	2019-12-16 21:50:40 UTC
+++ base/threading/thread_task_runner_handle.cc
@@ -8,6 +8,7 @@
 #include <utility>
 
 #include "base/bind.h"
+#include "base/callback_helpers.h"
 #include "base/lazy_instance.h"
 #include "base/logging.h"
 #include "base/run_loop.h"
@@ -38,6 +39,7 @@ bool ThreadTaskRunnerHandle::IsSet() {
   return !!thread_task_runner_tls.Pointer()->Get();
 }
 
+#if defined(OS_BSD)
 // static
 ScopedClosureRunner ThreadTaskRunnerHandle::OverrideForTesting(
     scoped_refptr<SingleThreadTaskRunner> overriding_task_runner) {
@@ -82,6 +84,7 @@ ScopedClosureRunner ThreadTaskRunnerHandle::OverrideFo
       base::Unretained(ttrh->task_runner_.get()),
       std::move(no_running_during_override)));
 }
+#endif
 
 ThreadTaskRunnerHandle::ThreadTaskRunnerHandle(
     scoped_refptr<SingleThreadTaskRunner> task_runner)
