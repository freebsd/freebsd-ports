--- src/remmina_ssh.c.orig	2023-03-02 13:25:58 UTC
+++ src/remmina_ssh.c
@@ -479,7 +479,7 @@ remmina_ssh_cp_to_ch_cb(int fd, int revents, void *use
 {
 	TRACE_CALL(__func__);
 	ssh_channel channel = (ssh_channel)userdata;
-	gchar buf[0x200000];
+	gchar buf[524288];
 	gint sz = 0, ret = 0;
 
 	node_t *temp_node = remmina_ssh_search_item(channel);
