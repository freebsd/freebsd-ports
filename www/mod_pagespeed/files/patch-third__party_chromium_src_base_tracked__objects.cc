--- third_party/chromium/src/base/tracked_objects.cc.orig	2017-09-12 17:33:52 UTC
+++ third_party/chromium/src/base/tracked_objects.cc
@@ -378,7 +378,7 @@ void ThreadData::OnThreadTerminationClea
   }
   // We must NOT do any allocations during this callback.
   // Using the simple linked lists avoids all allocations.
-  DCHECK_EQ(this->next_retired_worker_, reinterpret_cast<ThreadData*>(NULL));
+  DCHECK_EQ(this->next_retired_worker_, reinterpret_cast<ThreadData*>((void *)NULL));
   this->next_retired_worker_ = first_retired_worker_;
   first_retired_worker_ = this;
 }
