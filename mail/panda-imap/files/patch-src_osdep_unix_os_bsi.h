--- src/osdep/unix/os_bsi.h.orig	Sat Oct 19 20:30:04 1996
+++ src/osdep/unix/os_bsi.h	Sun May 24 10:46:33 1998
@@ -37,7 +37,18 @@
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
 #include <syslog.h>
 #include <sys/file.h>
