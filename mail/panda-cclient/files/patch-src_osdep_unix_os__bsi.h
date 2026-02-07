--- src/osdep/unix/os_bsi.h.orig	Wed Apr 11 10:53:03 2001
+++ src/osdep/unix/os_bsi.h	Wed Apr 11 10:55:32 2001
@@ -22,7 +22,18 @@
 #include <unistd.h>
 #include <string.h>
 #include <sys/types.h>
+
+/*
+ * FreeBSD v3.x and onward whines about <sys/dir.h> being obsolete, so switch
+ * to POSIX semantics.
+ */
+#if    __FreeBSD__ >= 3
+#include <dirent.h>
+#define direct dirent
+#else
 #include <sys/dir.h>
+#endif
+
 #include <fcntl.h>
 #include <syslog.h>
 #include <sys/file.h>
