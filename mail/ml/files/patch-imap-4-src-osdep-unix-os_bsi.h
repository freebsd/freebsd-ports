--- ../imap-4/src/osdep/unix/os_bsi.h.orig	Mon Mar 30 17:07:22 1998
+++ ../imap-4/src/osdep/unix/os_bsi.h	Sat Jun 26 02:13:22 1999
@@ -34,13 +34,25 @@
  */
 
 #define MAILFILE "/var/mail/%s"
-#define ACTIVEFILE "/usr/lib/news/active"
-#define NEWSSPOOL "/usr/spool/news"
+#define ACTIVEFILE "/usr/local/news/db/active"		/* inn-stable port */
+#define NEWSSPOOL "/var/spool/news"			/* inn-stable port */
 
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+
+/*
+ * From ports/mail/imap-uw:
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
 #include <sys/uio.h>		/* needed for writev() prototypes */
 #include <syslog.h>
 #include <sys/file.h>
