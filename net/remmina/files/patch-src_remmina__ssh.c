--- src/remmina_ssh.c.orig	2022-06-20 10:37:40 UTC
+++ src/remmina_ssh.c
@@ -478,7 +478,7 @@ remimna_ssh_cp_to_ch_cb(int fd, int revents, void *use
 {
 	TRACE_CALL(__func__);
 	ssh_channel channel = (ssh_channel)userdata;
-	gchar buf[2097152];
+	gchar buf[524288];
 	gint sz = 0, ret = 0;
 
 	node_t *temp_node = remmina_ssh_search_item(channel);
