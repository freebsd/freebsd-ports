--- usr/lib/common/trace.c.orig	2018-11-16 14:53:03 UTC
+++ usr/lib/common/trace.c
@@ -21,6 +21,7 @@
 #include <unistd.h>
 #include <sys/file.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 
 #include "pkcs11types.h"
 #include "defs.h"
@@ -170,7 +171,7 @@ CK_RV trace_initialize(void)
         return (CKR_FUNCTION_FAILED);
     }
 
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (grp == NULL) {
         OCK_SYSLOG(LOG_ERR, "getgrnam(pkcs11) failed: %s."
                    "Tracing is disabled.\n", strerror(errno));
