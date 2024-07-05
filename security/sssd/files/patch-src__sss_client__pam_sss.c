--- src/sss_client/pam_sss.c.orig	2020-03-17 13:31:28 UTC
+++ src/sss_client/pam_sss.c
@@ -266,9 +266,9 @@ static int do_pam_conversation(pam_handle_t *pamh, con
 
         pam_msg->msg_style = msg_style;
         if (state == SSS_PAM_CONV_REENTER) {
-            pam_msg->msg = reenter_msg;
+            pam_msg->msg = (char *)(intptr_t)reenter_msg;
         } else {
-            pam_msg->msg = msg;
+            pam_msg->msg = (char *)(intptr_t)msg;
         }
 
         mesg[0] = (const struct pam_message *) pam_msg;
@@ -1253,7 +1253,7 @@ static int get_pam_items(pam_handle_t *pamh, uint32_t 
 
     pi->cli_pid = getpid();
 
-    pi->login_name = pam_modutil_getlogin(pamh);
+    pi->login_name = getlogin();
     if (pi->login_name == NULL) pi->login_name="";
 
     pi->domain_name = NULL;
