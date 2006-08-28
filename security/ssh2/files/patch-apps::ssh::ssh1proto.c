--- apps/ssh/ssh1proto.c.orig	2003-12-03 15:17:26.000000000 +0200
+++ apps/ssh/ssh1proto.c
@@ -3918,7 +3918,7 @@ void ssh1_handle_packet_smsg_auth_rsa_ch
                           SSH_FORMAT_UINT32_STR,
                           challenge_buf, challenge_len,
                           SSH_FORMAT_UINT32_STR,
-                          ssh1->session_id, 16,
+                          ssh1->session_id, (size_t) 16,
                           SSH_FORMAT_END);
         ssh_xfree(challenge_buf);
         ssh1->mode = SSH1_AGENT_OPERATION_IN_PROGRESS;
