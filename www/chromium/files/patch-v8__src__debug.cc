--- v8/src/debug.cc.orig	2015-04-19 19:02:03.000000000 +0200
+++ v8/src/debug.cc	2015-04-19 19:02:41.000000000 +0200
@@ -573,7 +573,7 @@
   thread_local_.step_out_fp_ = 0;
   // TODO(isolates): frames_are_dropped_?
   base::NoBarrier_Store(&thread_local_.current_debug_scope_,
-                        reinterpret_cast<base::AtomicWord>(0));
+                        static_cast<base::AtomicWord>(0));
   thread_local_.restarter_frame_function_pointer_ = NULL;
 }
 
