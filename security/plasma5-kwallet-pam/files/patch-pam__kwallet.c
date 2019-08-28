---pam_kwallet.c	2019-08-28 10:45:20.619019000 +0200
+++ pam_kwallet.c	2019-08-28 10:47:11.632255000 +0200
@@ -390,7 +390,7 @@ static void execute_kwallet(pam_handle_t *pamh, struct
     struct sockaddr_un local;
     local.sun_family = AF_UNIX;
 
-    if (strlen(fullSocket) > sizeof(local.sun_path)) {
+    if (strlen(fullSocket) >= sizeof(local.sun_path)) {
         syslog(LOG_ERR, "%s: socket path %s too long to open",
                    logPrefix, fullSocket);
         free(fullSocket);
@@ -403,8 +403,7 @@ static void execute_kwallet(pam_handle_t *pamh, struct
 
     syslog(LOG_DEBUG, "%s: final socket path: %s", logPrefix, local.sun_path);
 
-    size_t len = strlen(local.sun_path) + sizeof(local.sun_family);
-    if (bind(envSocket, (struct sockaddr *)&local, len) == -1) {
+    if (bind(envSocket, (struct sockaddr *)&local, sizeof(local)) == -1) {
         syslog(LOG_INFO, "%s-kwalletd: Couldn't bind to local file\n", logPrefix);
         goto cleanup;
     }
