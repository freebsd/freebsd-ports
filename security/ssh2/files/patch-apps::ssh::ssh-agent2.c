--- apps/ssh/ssh-agent2.c.orig	2003-12-03 15:17:27.000000000 +0200
+++ apps/ssh/ssh-agent2.c
@@ -1802,7 +1802,7 @@ void ssh_agenti_ssh1_encode_mp(SshBuffer
   num_buf = ssh_xmalloc(num_buf_len);
   ssh_mp_get_buf(num_buf, num_buf_len, n);
   ssh_encode_buffer(buffer,
-                    SSH_FORMAT_DATA, len_buf, 2,
+                    SSH_FORMAT_DATA, len_buf, (size_t) 2,
                     SSH_FORMAT_DATA, num_buf, num_buf_len,
                     SSH_FORMAT_END);
   ssh_xfree(num_buf);
