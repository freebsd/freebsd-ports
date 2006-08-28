--- apps/ssh/ssh-signer2.c.orig	2003-12-03 15:17:26.000000000 +0200
+++ apps/ssh/ssh-signer2.c
@@ -264,7 +264,7 @@ SSH_FSM_STEP(signer_send_error)
                            (unsigned int) gdata->error_code_to_ssh2,
                            SSH_FORMAT_UINT32_STR, gdata->error_message_to_ssh2,
                            strlen(gdata->error_message_to_ssh2),
-                           SSH_FORMAT_UINT32_STR, "en", 2,
+                           SSH_FORMAT_UINT32_STR, "en", (size_t) 2,
                            SSH_FORMAT_END);
 
   ssh_packet_wrapper_can_receive(gdata->wrapper, FALSE);
