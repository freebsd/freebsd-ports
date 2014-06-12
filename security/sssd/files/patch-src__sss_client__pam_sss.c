From 18bce9f12311c6e7a7fe4350150120a98b3ec106 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Wed, 6 Nov 2013 22:01:21 +0100
Subject: [PATCH 2/2] patch-src__sss_client__pam_sss.c

---
 src/sss_client/pam_sss.c | 24 ++++++++++++++++++++++++
 1 file changed, 24 insertions(+)

diff --git src/sss_client/pam_sss.c src/sss_client/pam_sss.c
index 5fd276ccba15da1f689b1939a02288dda7a09d89..e35552f7e612d3e68f957845998a8105437af301 100644
--- src/sss_client/pam_sss.c
+++ src/sss_client/pam_sss.c
@@ -52,6 +52,8 @@
 #define FLAGS_USE_FIRST_PASS (1 << 0)
 #define FLAGS_FORWARD_PASS   (1 << 1)
 #define FLAGS_USE_AUTHTOK    (1 << 2)
+#define FLAGS_IGNORE_UNKNOWN_USER (1 << 3)
+#define FLAGS_IGNORE_AUTHINFO_UNAVAIL (1 << 4)
 
 #define PWEXP_FLAG "pam_sss:password_expired_flag"
 #define FD_DESTRUCTOR "pam_sss:fd_destructor"
@@ -125,10 +127,12 @@ static void free_exp_data(pam_handle_t *pamh, void *ptr, int err)
 
 static void close_fd(pam_handle_t *pamh, void *ptr, int err)
 {
+#ifdef PAM_DATA_REPLACE
     if (err & PAM_DATA_REPLACE) {
         /* Nothing to do */
         return;
     }
+#endif /* PAM_DATA_REPLACE */
 
     D(("Closing the fd"));
     sss_pam_close_fd();
@@ -1292,6 +1296,10 @@ static void eval_argv(pam_handle_t *pamh, int argc, const char **argv,
             }
         } else if (strcmp(*argv, "quiet") == 0) {
             *quiet_mode = true;
+        } else if (strcmp(*argv, "ignore_unknown_user") == 0) {
+            *flags |= FLAGS_IGNORE_UNKNOWN_USER;
+        } else if (strcmp(*argv, "ignore_authinfo_unavail") == 0) {
+            *flags |= FLAGS_IGNORE_AUTHINFO_UNAVAIL;
         } else {
             logger(pamh, LOG_WARNING, "unknown option: %s", *argv);
         }
@@ -1429,6 +1437,13 @@ static int pam_sss(enum sss_cli_command task, pam_handle_t *pamh,
     ret = get_pam_items(pamh, &pi);
     if (ret != PAM_SUCCESS) {
         D(("get items returned error: %s", pam_strerror(pamh,ret)));
+        if (flags & FLAGS_IGNORE_UNKNOWN_USER && ret == PAM_USER_UNKNOWN) {
+            ret = PAM_IGNORE;
+        }
+        if (flags & FLAGS_IGNORE_AUTHINFO_UNAVAIL
+                && ret == PAM_AUTHINFO_UNAVAIL) {
+            ret = PAM_IGNORE;
+        }
         return ret;
     }
 
@@ -1467,6 +1482,15 @@ static int pam_sss(enum sss_cli_command task, pam_handle_t *pamh,
 
         pam_status = send_and_receive(pamh, &pi, task, quiet_mode);
 
+        if (flags & FLAGS_IGNORE_UNKNOWN_USER
+                && pam_status == PAM_USER_UNKNOWN) {
+            pam_status = PAM_IGNORE;
+        }
+        if (flags & FLAGS_IGNORE_AUTHINFO_UNAVAIL
+                && pam_status == PAM_AUTHINFO_UNAVAIL) {
+            pam_status = PAM_IGNORE;
+        }
+
         switch (task) {
             case SSS_PAM_AUTHENTICATE:
                 /* We allow sssd to send the return code PAM_NEW_AUTHTOK_REQD during
-- 
1.9.3

