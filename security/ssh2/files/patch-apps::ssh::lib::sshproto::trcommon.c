--- apps/ssh/lib/sshproto/trcommon.c.orig	2003-12-03 15:17:33.000000000 +0200
+++ apps/ssh/lib/sshproto/trcommon.c
@@ -555,7 +555,7 @@ void ssh_tr_send_packet(SshTransportComm
       SSH_DEBUG(5, ("Outgoing empty, sending empty ignore packet."));
       ret = ssh_encode_buffer(&new_packet,
                               SSH_FORMAT_CHAR, (unsigned int) SSH_MSG_IGNORE,
-                              SSH_FORMAT_UINT32, 0L,
+                              SSH_FORMAT_UINT32, (SshUInt32) 0,
                               SSH_FORMAT_END);
       SSH_VERIFY(ret > 0);
       ssh_tr_encode_packet(tr, ssh_buffer_ptr(&new_packet),
@@ -3171,7 +3171,7 @@ void ssh_tr_process_up_incoming_packet(S
 
           ssh_encode_buffer(new_packet,
                             SSH_FORMAT_CHAR, (unsigned int) SSH_MSG_IGNORE,
-                            SSH_FORMAT_UINT32, ignore_len,
+                            SSH_FORMAT_UINT32, (SshUInt32) ignore_len,
                             SSH_FORMAT_END);
 
           ssh_xbuffer_append_space(new_packet, &datap, ignore_len);
