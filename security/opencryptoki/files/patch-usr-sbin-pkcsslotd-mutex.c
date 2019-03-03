--- usr/sbin/pkcsslotd/mutex.c.orig	2018-11-16 14:53:03 UTC
+++ usr/sbin/pkcsslotd/mutex.c
@@ -16,10 +16,29 @@
 #include <sys/stat.h>
 #include <grp.h>
 #include <string.h>
+#include <fcntl.h>
 
 #include "log.h"
 #include "slotmgr.h"
 
+#ifdef __sun
+#define	LOCK_EX F_LOCK
+#define	LOCK_UN F_ULOCK
+#define	flock(fd, func) lockf(fd, func, 0)
+#endif
+#ifndef	LOCK_SH
+#define	LOCK_SH 1       /* shared lock */
+#endif
+#ifndef	LOCK_EX
+#define	LOCK_EX 2       /* exclusive lock */
+#endif
+#ifndef	LOCK_NB
+#define	LOCK_NB 4       /* don't block when locking */
+#endif
+#ifndef	LOCK_UN
+#define	LOCK_UN 8       /* unlock */
+#endif
+
 static int xplfd = -1;
 
 int CreateXProcLock(void)
@@ -41,7 +60,7 @@ int CreateXProcLock(void)
                     goto error;
                 }
 
-                grp = getgrnam("pkcs11");
+                grp = getgrnam(PKCS11GROUP);
                 if (grp != NULL) {
                     if (fchown(xplfd, -1, grp->gr_gid) == -1) {
                         DbgLog(DL0, "%s:fchown(%s):%s\n",
