--- reslimits.c.orig	Thu Mar  7 16:11:25 2002
+++ reslimits.c	Thu Mar  7 16:11:48 2002
@@ -9,6 +9,7 @@
 #ifndef NORLIMIT
 
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/time.h>
 #include <sys/resource.h>
 
