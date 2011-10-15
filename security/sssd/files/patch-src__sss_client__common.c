--- ./src/sss_client/common.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/sss_client/common.c	2011-10-13 12:15:03.000000000 -0400
@@ -26,6 +26,7 @@
 #include "config.h"
 
 #include <nss.h>
+#include <nsswitch.h>
 #include <security/pam_modules.h>
 #include <errno.h>
 #include <sys/types.h>
@@ -111,7 +112,6 @@
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
             break;
         case 1:
             if (pfd.revents & (POLLERR | POLLHUP | POLLNVAL)) {
@@ -216,7 +216,6 @@
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
             break;
         case 1:
             if (pfd.revents & (POLLERR | POLLHUP | POLLNVAL)) {
@@ -638,7 +637,6 @@
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
             break;
         case 1:
             if (pfd.revents & (POLLERR | POLLHUP | POLLNVAL)) {
@@ -688,23 +686,23 @@
     /* avoid looping in the nss daemon */
     envval = getenv("_SSS_LOOPS");
     if (envval && strcmp(envval, "NO") == 0) {
-        return NSS_STATUS_NOTFOUND;
+        return NS_NOTFOUND;
     }
 
     ret = sss_cli_check_socket(errnop, SSS_NSS_SOCKET_NAME);
     if (ret != SSS_STATUS_SUCCESS) {
-        return NSS_STATUS_UNAVAIL;
+        return NS_UNAVAIL;
     }
 
     ret = sss_cli_make_request_nochecks(cmd, rd, repbuf, replen, errnop);
     switch (ret) {
     case SSS_STATUS_TRYAGAIN:
-        return NSS_STATUS_TRYAGAIN;
+        return NS_TRYAGAIN;
     case SSS_STATUS_SUCCESS:
-        return NSS_STATUS_SUCCESS;
+        return NS_SUCCESS;
     case SSS_STATUS_UNAVAIL:
     default:
-        return NSS_STATUS_UNAVAIL;
+        return NS_UNAVAIL;
     }
 }
 
