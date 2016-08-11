--- usr/lib/pkcs11/common/trace.c.orig	2016-04-29 17:26:46 UTC
+++ usr/lib/pkcs11/common/trace.c
@@ -301,6 +301,7 @@
 #include <unistd.h>
 #include <sys/file.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 
 #include "pkcs11types.h"
 #include "defs.h"
@@ -449,7 +450,7 @@ CK_RV trace_initialize(void)
 		return(CKR_FUNCTION_FAILED);
 	}
 
-	grp = getgrnam("pkcs11");
+	grp = getgrnam(PKCS11GROUP);
 	if (grp == NULL) {
 		OCK_SYSLOG(LOG_ERR, "getgrnam(pkcs11) failed: %s."
 			   "Tracing is disabled.\n", strerror(errno));
