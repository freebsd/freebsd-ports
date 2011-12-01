--- lib/backtrace.c.orig	2011-11-01 12:07:55.000000000 +0100
+++ lib/backtrace.c	2011-11-01 12:09:28.000000000 +0100
@@ -83,6 +83,7 @@
 void
 backtrace_capture(struct backtrace *backtrace)
 {
+#ifndef __FreeBSD__
     void **frame;
     size_t n;
 
@@ -95,4 +96,7 @@
         backtrace->frames[n++] = (uintptr_t) frame[1];
     }
     backtrace->n_frames = n;
+#else
+    backtrace->n_frames = 0;
+#endif
 }
