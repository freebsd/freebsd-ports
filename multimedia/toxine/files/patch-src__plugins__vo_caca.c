--- ./src/plugins/vo_caca.c.orig	Thu May  6 18:16:03 2004
+++ ./src/plugins/vo_caca.c	Sun Apr 15 16:26:25 2007
@@ -27,6 +27,9 @@
 #include <unistd.h>
 #include <errno.h>
 #include <caca.h>
+#ifdef CACA_API_VERSION_1
+#include <caca0.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
