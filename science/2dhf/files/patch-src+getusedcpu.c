--- src/getusedcpu.c.orig	Sat Jan  4 21:21:37 2003
+++ src/getusedcpu.c	Tue Aug  5 07:02:39 2003
@@ -67,7 +67,6 @@
 #include <string.h>
 #include <ctype.h>
 
-
 #include <sys/types.h>
 #include <sys/times.h>
 #include <sys/param.h>
@@ -76,7 +75,7 @@
 #include <sys/acct.h>
 #endif
 
-#if defined(ymp)
+#if defined(ymp) || defined (__FreeBSD__)
 #include <time.h>
 #endif
 
@@ -106,7 +105,7 @@
 #if defined(dec)
    start       = (float)(buffer.tms_utime  + buffer.tms_stime) / (float)(AHZ);
    start_child = (float)(buffer.tms_cutime + buffer.tms_cstime)/ (float)(AHZ);
-#elif defined(ymp)
+#elif defined(ymp) || defined(__FreeBSD__)
    start       = (float)(buffer.tms_utime  + buffer.tms_stime)  / (float)(CLK_TCK);
    start_child = (float)(buffer.tms_cutime + buffer.tms_cstime) / (float)(CLK_TCK);
 #else
@@ -118,7 +117,7 @@
 #if defined(dec)
    *Msecs = (float)(buffer.tms_utime  + buffer.tms_stime) / (float)(AHZ) - start_child;
    *Csecs = (float)(buffer.tms_cutime + buffer.tms_cstime)/ (float)(AHZ) - start_child;
-#elif defined(ymp)
+#elif defined(ymp) || defined(__FreeBSD__)
    *Msecs = (float)(buffer.tms_utime  + buffer.tms_stime)  / (float)(CLK_TCK) - start;
    *Csecs = (float)(buffer.tms_cutime + buffer.tms_cstime) / (float)(CLK_TCK) - start_child;
 #else
