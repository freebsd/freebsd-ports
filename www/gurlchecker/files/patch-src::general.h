--- src/general.h.orig	Wed May 28 19:29:40 2003
+++ src/general.h	Sun Jun  1 21:50:33 2003
@@ -33,7 +33,16 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+
+#ifdef __linux__
 #include <sys/vfs.h>
+#endif
+
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/mount.h>
+#endif
+
 #include <signal.h>
 #include <setjmp.h>
 #include <sys/types.h>
