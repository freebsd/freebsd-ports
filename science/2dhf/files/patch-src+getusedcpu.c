--- src/getusedcpu.c.orig	Sat Jan  4 21:21:37 2003
+++ src/getusedcpu.c	Thu Jul 24 17:30:40 2003
@@ -66,7 +66,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
-
+#ifdef __FreeBSD__ 
+#include <sys/unistd.h>
+#endif
 
 #include <sys/types.h>
 #include <sys/times.h>
@@ -109,6 +111,9 @@
 #elif defined(ymp)
    start       = (float)(buffer.tms_utime  + buffer.tms_stime)  / (float)(CLK_TCK);
    start_child = (float)(buffer.tms_cutime + buffer.tms_cstime) / (float)(CLK_TCK);
+#elif defined(__FreeBSD__)
+   start       = (float)(buffer.tms_utime  + buffer.tms_stime)  / (float)(_SC_CLK_TCK);
+   start_child = (float)(buffer.tms_cutime + buffer.tms_cstime) / (float)(_SC_CLK_TCK);
 #else
    start       = (float)(buffer.tms_utime  + buffer.tms_stime)  / (float)(HZ);
    start_child = (float)(buffer.tms_cutime + buffer.tms_cstime) / (float)(HZ);
@@ -121,6 +126,9 @@
 #elif defined(ymp)
    *Msecs = (float)(buffer.tms_utime  + buffer.tms_stime)  / (float)(CLK_TCK) - start;
    *Csecs = (float)(buffer.tms_cutime + buffer.tms_cstime) / (float)(CLK_TCK) - start_child;
+#elif defined(__FreeBSD__)
+   *Msecs = (float)(buffer.tms_utime  + buffer.tms_stime)  / (float)(_SC_CLK_TCK) - start;
+   *Csecs = (float)(buffer.tms_cutime + buffer.tms_cstime) / (float)(_SC_CLK_TCK) - start_child;
 #else
    *Msecs = (float)(buffer.tms_utime  + buffer.tms_stime)  / (float)(HZ) - start;
    *Csecs = (float)(buffer.tms_cutime + buffer.tms_cstime) / (float)(HZ) - start_child;
