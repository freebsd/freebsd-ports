--- base/tracked_objects.cc	2013-07-03 23:39:54.000000000 -0400
+++ base/tracked_objects.cc	2013-07-19 00:42:10.000000000 -0400
@@ -346,7 +346,7 @@
   }
   // We must NOT do any allocations during this callback.
   // Using the simple linked lists avoids all allocations.
-  DCHECK_EQ(this->next_retired_worker_, reinterpret_cast<ThreadData*>(NULL));
+  DCHECK_EQ(this->next_retired_worker_, static_cast<ThreadData*>(0));
   this->next_retired_worker_ = first_retired_worker_;
   first_retired_worker_ = this;
 }
