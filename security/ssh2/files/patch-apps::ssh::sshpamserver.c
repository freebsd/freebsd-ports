--- apps/ssh/sshpamserver.c.orig	2003-12-03 15:17:26.000000000 +0200
+++ apps/ssh/sshpamserver.c
@@ -306,7 +306,8 @@ int send_packet(int fd, SshPacketType pa
 
   buffer = ssh_xbuffer_allocate();
   ssh_encode_buffer(buffer,
-                    SSH_FORMAT_UINT32, ssh_buffer_len(packet) + 1,
+                    SSH_FORMAT_UINT32,
+		    (SshUInt32) (ssh_buffer_len(packet) + 1),
                     SSH_FORMAT_CHAR, (unsigned int)packet_type,
                     SSH_FORMAT_DATA, ssh_buffer_ptr(packet),
                     ssh_buffer_len(packet),
