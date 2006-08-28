--- apps/ssh/lib/sshproto/sshconn.c.orig	2003-12-03 15:17:34.000000000 +0200
+++ apps/ssh/lib/sshproto/sshconn.c
@@ -452,7 +452,8 @@ Boolean ssh_conn_send_channel_data_type(
                                      (unsigned int) SSH_MSG_CHANNEL_DATA,
                                      SSH_FORMAT_UINT32, (SshUInt32)
                                      channel->remote_id,
-                                     SSH_FORMAT_UINT32_STR, buf, len,
+                                     SSH_FORMAT_UINT32_STR, buf,
+				     (size_t) len,
                                      SSH_FORMAT_END);
         }
       else
@@ -465,7 +466,8 @@ Boolean ssh_conn_send_channel_data_type(
                                      SSH_FORMAT_UINT32, (SshUInt32)
                                      channel->remote_id,
                                      SSH_FORMAT_UINT32, (SshUInt32) i,
-                                     SSH_FORMAT_UINT32_STR, buf, len,
+                                     SSH_FORMAT_UINT32_STR, buf,
+				     (size_t) len,
                                      SSH_FORMAT_END);
         }
 
