--- compat/cpu.h.orig	2021-05-10 02:02:34.000000000 -0700
+++ compat/cpu.h	2021-11-29 10:31:25.381434000 -0800
@@ -15,6 +15,8 @@
 #if HAVE_SCHED_H
 #include <sched.h>
 #endif
+#undef CPU_COUNT
+#undef CPU_AND
 
 #if !HAVE_CPU_AFFINITY
 /* failing replacements to minimize the number of if-HAVE_CPU_AFFINITYs */
