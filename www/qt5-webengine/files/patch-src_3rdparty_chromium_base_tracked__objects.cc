--- src/3rdparty/chromium/base/tracked_objects.cc.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/base/tracked_objects.cc
@@ -431,7 +431,7 @@ void ThreadData::OnThreadTerminationCleanup() {
   }
   // We must NOT do any allocations during this callback.
   // Using the simple linked lists avoids all allocations.
-  DCHECK_EQ(this->next_retired_worker_, reinterpret_cast<ThreadData*>(NULL));
+  DCHECK_EQ(this->next_retired_worker_, reinterpret_cast<ThreadData*>(0));
   this->next_retired_worker_ = first_retired_worker_;
   first_retired_worker_ = this;
 }
