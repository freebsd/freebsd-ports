--- src/cpu_freebsd.c.orig	Sat Mar  8 03:40:25 2003
+++ src/cpu_freebsd.c	Wed Nov 30 13:42:56 2005
@@ -75,7 +75,7 @@
     used = cpu_time[CP_USER] + cpu_time[CP_SYS];
     if (!opts->ignore_nice)
 	used += cpu_time[CP_NICE];
-    total = used + cpu_time[CP_IDLE];
+    total = used + cpu_time[CP_IDLE] + cpu_time[CP_NICE];
 
     if (pre_total == 0) {
 	result = 0;
