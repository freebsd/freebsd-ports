diff --git src/sss_client/common.c src/sss_client/common.c
index d8effb6dd..edeb4a159 100644
--- src/sss_client/common.c
+++ src/sss_client/common.c
@@ -25,6 +25,7 @@
 #include "config.h"
 
 #include <nss.h>
+#include <nsswitch.h>
 #include <security/pam_modules.h>
 #include <errno.h>
 #include <sys/types.h>
@@ -44,6 +45,7 @@
 #define _(STRING) dgettext (PACKAGE, STRING)
 #include "sss_cli.h"
 #include "common_private.h"
+#include "util/sss_bsd_errno.h"
 
 #if HAVE_PTHREAD
 #include <pthread.h>
@@ -126,7 +128,6 @@ static enum sss_status sss_cli_send_req(enum sss_cli_command cmd,
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
             break;
         case 1:
             if (pfd.revents & (POLLERR | POLLHUP | POLLNVAL)) {
@@ -235,7 +236,6 @@ static enum sss_status sss_cli_recv_rep(enum sss_cli_command cmd,
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
             break;
         case 1:
             if (pfd.revents & (POLLHUP)) {
@@ -679,7 +679,6 @@ static enum sss_status sss_cli_check_socket(int *errnop,
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
             break;
         case 1:
             if (pfd.revents & (POLLERR | POLLHUP | POLLNVAL)) {
@@ -730,7 +729,7 @@ enum nss_status sss_nss_make_request_timeout(enum sss_cli_command cmd,
     /* avoid looping in the nss daemon */
     envval = getenv("_SSS_LOOPS");
     if (envval && strcmp(envval, "NO") == 0) {
-        return NSS_STATUS_NOTFOUND;
+        return NS_NOTFOUND;
     }
 
     ret = sss_cli_check_socket(errnop, SSS_NSS_SOCKET_NAME, timeout);
@@ -738,9 +737,9 @@ enum nss_status sss_nss_make_request_timeout(enum sss_cli_command cmd,
 #ifdef NONSTANDARD_SSS_NSS_BEHAVIOUR
         *errnop = 0;
         errno = 0;
-        return NSS_STATUS_NOTFOUND;
+        return NS_NOTFOUND;
 #else
-        return NSS_STATUS_UNAVAIL;
+        return NS_UNAVAIL;
 #endif
     }
 
@@ -765,17 +764,17 @@ enum nss_status sss_nss_make_request_timeout(enum sss_cli_command cmd,
     }
     switch (ret) {
     case SSS_STATUS_TRYAGAIN:
-        return NSS_STATUS_TRYAGAIN;
+        return NS_TRYAGAIN;
     case SSS_STATUS_SUCCESS:
-        return NSS_STATUS_SUCCESS;
+        return NS_SUCCESS;
     case SSS_STATUS_UNAVAIL:
     default:
 #ifdef NONSTANDARD_SSS_NSS_BEHAVIOUR
         *errnop = 0;
         errno = 0;
-        return NSS_STATUS_NOTFOUND;
+        return NS_NOTFOUND;
 #else
-        return NSS_STATUS_UNAVAIL;
+        return NS_UNAVAIL;
 #endif
     }
 }
