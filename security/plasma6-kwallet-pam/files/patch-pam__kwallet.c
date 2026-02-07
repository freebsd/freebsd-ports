---pam_kwallet.c	2019-08-28 10:45:20.619019000 +0200
--- pam_kwallet.c.orig	2021-09-16 08:40:28 UTC
+++ pam_kwallet.c
@@ -367,7 +367,7 @@ static void execute_kwallet(pam_handle_t *pamh, struct
     struct sockaddr_un local = {};
     local.sun_family = AF_UNIX;
 
-    if (strlen(fullSocket) > sizeof(local.sun_path)) {
+    if (strlen(fullSocket) >= sizeof(local.sun_path)) {
         syslog(LOG_ERR, "%s: socket path %s too long to open",
                    logPrefix, fullSocket);
         free(fullSocket);
