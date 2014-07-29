Index: lib/util.c
diff -u -p lib/util.c.orig lib/util.c
--- lib/util.c.orig	2012-04-18 20:28:37.000000000 +0900
+++ lib/util.c	2012-04-18 22:29:24.521844579 +0900
@@ -55,6 +55,9 @@
 #include <syslog.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifdef HAVE_STDINT_H
+#include <stdint.h>
+#endif
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
