--- reslimits.c.orig	Sat May 24 15:07:41 2003
+++ reslimits.c		Sat May 24 15:08:01 2003
@@ -9,6 +9,7 @@
 #ifndef NORLIMIT
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/time.h>
 #include <sys/resource.h>
 
