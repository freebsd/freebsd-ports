--- usr/lib/common/utility.c.orig	2018-11-16 14:53:03 UTC
+++ usr/lib/common/utility.c
@@ -21,6 +21,7 @@
 #include <errno.h>
 #include <pwd.h>
 #include <grp.h>
+#include <fcntl.h>
 
 #include "pkcs11types.h"
 #include "defs.h"
@@ -35,6 +36,25 @@
 #include <sys/file.h>
 #include <syslog.h>
 
+#ifdef __sun
+#define	LOCK_EX F_LOCK
+#define	LOCK_UN F_ULOCK
+#define	flock(fd, func) lockf(fd, func, 0)
+#endif
+
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
 // Function:  dlist_add_as_first()
 //
 // Adds the specified node to the start of the list
@@ -317,7 +337,7 @@ CK_RV CreateXProcLock(char *tokname, STDLL_TokData_t *
                            lockdir, strerror(errno));
                 goto err;
             }
-            grp = getgrnam("pkcs11");
+            grp = getgrnam(PKCS11GROUP);
             if (grp == NULL) {
                 fprintf(stderr, "getgrname(pkcs11): %s", strerror(errno));
                 goto err;
@@ -355,7 +375,7 @@ CK_RV CreateXProcLock(char *tokname, STDLL_TokData_t *
                     goto err;
                 }
 
-                grp = getgrnam("pkcs11");
+                grp = getgrnam(PKCS11GROUP);
                 if (grp != NULL) {
                     if (fchown(tokdata->spinxplfd, -1, grp->gr_gid) == -1) {
                         OCK_SYSLOG(LOG_ERR,
