--- src/vncshmimage.c.orig	2007-12-23 15:31:21.000000000 -0500
+++ src/vncshmimage.c	2007-12-23 15:32:10.000000000 -0500
@@ -12,6 +12,8 @@
 
 #include <string.h>
 
+#include <machine/param.h>
+#include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
 
