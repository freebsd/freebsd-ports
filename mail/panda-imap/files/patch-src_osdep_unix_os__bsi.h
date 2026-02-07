--- src/osdep/unix/os_bsi.h.orig	2022-04-17 00:12:02 UTC
+++ src/osdep/unix/os_bsi.h
@@ -27,7 +27,18 @@
 #include <unistd.h>
 #include <string.h>
 #include <sys/types.h>
+
+/*
+ * FreeBSD v3.x and onward whines about <sys/dir.h> being obsolete, so switch
+ * to POSIX semantics.
+ */
+#if	__FreeBSD__ >= 3
+#include <dirent.h>
+#define direct dirent
+#else
 #include <sys/dir.h>
+#endif
+
 #include <fcntl.h>
 #include <time.h>
 #include <utime.h>
