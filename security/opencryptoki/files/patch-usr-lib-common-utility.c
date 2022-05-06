--- usr/lib/common/utility.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/common/utility.c
@@ -21,6 +21,7 @@
 #include <errno.h>
 #include <pwd.h>
 #include <grp.h>
+#include <fcntl.h>
 #include <pthread.h>
 #include <openssl/evp.h>
 
@@ -40,6 +41,22 @@
 #include <sys/file.h>
 #include <syslog.h>
 
+#ifndef	LOCK_SH
+#define	LOCK_SH 1
+#endif
+
+#ifndef	LOCK_EX
+#define	LOCK_EX 2
+#endif
+
+#ifndef	LOCK_NB
+#define	LOCK_NB 4
+#endif
+
+#ifndef	LOCK_UN
+#define	LOCK_UN 8
+#endif
+
 CK_RV CreateXProcLock(char *tokname, STDLL_TokData_t *tokdata)
 {
     char lockfile[PATH_MAX];
@@ -82,7 +99,7 @@ CK_RV CreateXProcLock(char *tokname, STDLL_TokData_t *
                            lockdir, strerror(errno));
                 goto err;
             }
-            grp = getgrnam("pkcs11");
+            grp = getgrnam(PKCS11GROUP);
             if (grp == NULL) {
                 fprintf(stderr, "getgrname(pkcs11): %s", strerror(errno));
                 goto err;
@@ -122,7 +139,7 @@ CK_RV CreateXProcLock(char *tokname, STDLL_TokData_t *
                     goto err;
                 }
 
-                grp = getgrnam("pkcs11");
+                grp = getgrnam(PKCS11GROUP);
                 if (grp != NULL) {
                     if (fchown(tokdata->spinxplfd, -1, grp->gr_gid) == -1) {
                         OCK_SYSLOG(LOG_ERR,
