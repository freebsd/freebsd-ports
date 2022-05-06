--- usr/lib/common/loadsave.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/common/loadsave.c
@@ -20,17 +20,22 @@
 #include <string.h>
 #include <strings.h>
 #include <unistd.h>
+#if !defined(__FreeBSD__)
 #include <alloca.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ipc.h>
-#include <sys/file.h>
 #include <errno.h>
 #include <syslog.h>
 #include <pwd.h>
 #include <grp.h>
 #include <openssl/evp.h>
+#if !defined(__FreeBSD__)
 #include <endian.h>
+#else
+#include <sys/endian.h>
+#endif
 
 #include "pkcs11types.h"
 #include "defs.h"
@@ -132,7 +137,7 @@ void set_perm(int file)
         // Set absolute permissions or rw-rw----
         fchmod(file, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
 
-        grp = getgrnam("pkcs11");       // Obtain the group id
+        grp = getgrnam(PKCS11GROUP);       // Obtain the group id
         if (grp) {
             // set ownership to pkcs11 group
             if (fchown(file, -1, grp->gr_gid) != 0) {
@@ -303,7 +308,11 @@ CK_RV init_data_store(STDLL_TokData_t *tokdata, char *
         tokdata->pk_dir = NULL;
     }
 
+#if !defined(__FreeBSD__)
     if ((pkdir = secure_getenv("PKCS_APP_STORE")) != NULL) {
+#else
+    if ((pkdir = getenv("PKCS_APP_STORE")) != NULL) {
+#endif
         pklen = strlen(pkdir) + 1024;
         tokdata->pk_dir = (char *) calloc(pklen, 1);
         if (!(tokdata->pk_dir))
