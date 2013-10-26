From f40ad7e39f68345f3bfec169556463c1a13706e0 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 18/34] patch-src__sss_client__common.c

---
 src/sss_client/common.c | 20 +++++++++++---------
 1 file changed, 11 insertions(+), 9 deletions(-)

diff --git src/sss_client/common.c src/sss_client/common.c
index 6639ae1..d0b5c6d 100644
--- src/sss_client/common.c
+++ src/sss_client/common.c
@@ -25,6 +25,7 @@
 #include "config.h"
 
 #include <nss.h>
+#include <nsswitch.h>
 #include <security/pam_modules.h>
 #include <errno.h>
 #include <sys/types.h>
@@ -61,6 +62,10 @@
 #define SSS_DEFAULT_WRITE_FLAGS 0
 #endif
 
+#ifndef EOWNERDEAD
+#define EOWNERDEAD               130
+#endif
+
 /* common functions */
 
 int sss_cli_sd = -1; /* the sss client socket descriptor */
@@ -124,7 +129,6 @@ static enum sss_status sss_cli_send_req(enum sss_cli_command cmd,
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
             break;
         case 1:
             if (pfd.revents & (POLLERR | POLLHUP | POLLNVAL)) {
@@ -232,7 +236,6 @@ static enum sss_status sss_cli_recv_rep(enum sss_cli_command cmd,
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
             break;
         case 1:
             if (pfd.revents & (POLLHUP)) {
@@ -669,7 +672,6 @@ static enum sss_status sss_cli_check_socket(int *errnop, const char *socket_name
             *errnop = error;
             break;
         case 0:
-            *errnop = ETIME;
             break;
         case 1:
             if (pfd.revents & (POLLERR | POLLHUP | POLLNVAL)) {
@@ -719,23 +721,23 @@ enum nss_status sss_nss_make_request(enum sss_cli_command cmd,
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
 
@@ -984,7 +986,7 @@ errno_t sss_strnlen(const char *str, size_t maxlen, size_t *len)
     *len = 0;
     while (*len < maxlen) {
         if (str[*len] == '\0') break;
-        len++;
+        ++*len;
     }
 #endif
 
-- 
1.8.0

