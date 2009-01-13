--- dupmerge.c.orig	2008-03-01 17:46:41.000000000 +0100
+++ dupmerge.c	2009-01-13 15:15:07.000000000 +0100
@@ -125,6 +125,7 @@
 #include <sys/wait.h>           // vfork
 #include <time.h>               // localtime
 
+#include <roken.h>
 
 #define mc_MIN(a, b) ((a) < (b) ? (a) : (b))
 #define mc_MAX(a, b) ((a) > (b) ? (a) : (b))
