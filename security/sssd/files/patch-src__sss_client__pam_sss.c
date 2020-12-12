diff --git src/sss_client/pam_sss.c src/sss_client/pam_sss.c
index f634f7659..1de88fefe 100644
--- src/sss_client/pam_sss.c
+++ src/sss_client/pam_sss.c
@@ -263,9 +263,9 @@ static int do_pam_conversation(pam_handle_t *pamh, const int msg_style,
 
         pam_msg->msg_style = msg_style;
         if (state == SSS_PAM_CONV_REENTER) {
-            pam_msg->msg = reenter_msg;
+            pam_msg->msg = (char *)(intptr_t)reenter_msg;
         } else {
-            pam_msg->msg = msg;
+            pam_msg->msg = (char *)(intptr_t)msg;
         }
 
         mesg[0] = (const struct pam_message *) pam_msg;
