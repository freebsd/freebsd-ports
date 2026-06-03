--- cpu.c.orig	2026-02-23 13:07:38 UTC
+++ cpu.c
@@ -33,7 +33,7 @@
 //#define CPU_DEBUG
 
 
-#ifndef _MSC_VER
+#if defined(__i386__) || defined(__x86_64__)
 static
 void
 __cpuidex (int cpu_info[4], int function_id, int subfunction_id) {
