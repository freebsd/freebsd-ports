--- compat/cpu.h.orig	2021-12-07 14:15:52 UTC
+++ compat/cpu.h
@@ -15,6 +15,8 @@
 #if HAVE_SCHED_H
 #include <sched.h>
 #endif
+#undef CPU_COUNT
+#undef CPU_AND
 
 #if !HAVE_CPU_AFFINITY
 /* failing replacements to minimize the number of if-HAVE_CPU_AFFINITYs */
