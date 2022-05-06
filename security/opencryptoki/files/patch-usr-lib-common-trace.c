--- usr/lib/common/trace.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/common/trace.c
@@ -23,7 +23,10 @@
 #include <sys/file.h>
 #include <sys/types.h>
 #include <sys/syscall.h>
+#include <sys/stat.h>
 
+#include <pthread_np.h>
+
 #include "pkcs11types.h"
 #include "defs.h"
 #include "host_defs.h"
@@ -34,7 +37,7 @@
 #ifdef SYS_gettid
 #define __gettid() syscall(SYS_gettid)
 #else
-#define __gettid() gettid()
+#define __gettid() pthread_getthreadid_np()
 #endif
 
 pthread_mutex_t tlmtx = PTHREAD_MUTEX_INITIALIZER;
@@ -178,7 +181,7 @@ CK_RV trace_initialize(void)
         return (CKR_FUNCTION_FAILED);
     }
 
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (grp == NULL) {
         OCK_SYSLOG(LOG_ERR, "getgrnam(pkcs11) failed: %s."
                    "Tracing is disabled.\n", strerror(errno));
