--- main.h.orig	Tue Oct 10 00:38:35 2006
+++ main.h	Tue Oct 10 00:38:55 2006
@@ -35,6 +35,9 @@
 #include <sys/mount.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <libgen.h>
+#endif
 
 #define FALSE  0
 #define TRUE   1
