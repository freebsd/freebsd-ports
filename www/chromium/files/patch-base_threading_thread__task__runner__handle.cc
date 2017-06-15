--- base/threading/thread_task_runner_handle.cc.orig	2017-04-19 19:06:28 UTC
+++ base/threading/thread_task_runner_handle.cc
@@ -7,6 +7,7 @@
 #include <utility>
 
 #include "base/bind.h"
+#include "base/callback_helpers.h"
 #include "base/lazy_instance.h"
 #include "base/logging.h"
 #include "base/memory/ptr_util.h"
@@ -34,6 +35,7 @@ bool ThreadTaskRunnerHandle::IsSet() {
   return !!lazy_tls_ptr.Pointer()->Get();
 }
 
+#if defined(OS_BSD)
 // static
 ScopedClosureRunner ThreadTaskRunnerHandle::OverrideForTesting(
     scoped_refptr<SingleThreadTaskRunner> overriding_task_runner) {
@@ -77,6 +79,7 @@ ScopedClosureRunner ThreadTaskRunnerHand
       base::Passed(&overriding_task_runner),
       base::Unretained(ttrh->task_runner_.get())));
 }
+#endif
 
 ThreadTaskRunnerHandle::ThreadTaskRunnerHandle(
     scoped_refptr<SingleThreadTaskRunner> task_runner)
