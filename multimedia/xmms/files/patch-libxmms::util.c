--- libxmms/util.c.orig	Fri Jun  1 15:07:49 2001
+++ libxmms/util.c	Sun Oct  6 18:40:25 2002
@@ -11,6 +11,7 @@
 #endif
 
 #ifdef __FreeBSD__
+#include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
 
