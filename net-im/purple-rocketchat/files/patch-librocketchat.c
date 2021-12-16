--- librocketchat.c.orig	2021-10-02 03:16:50 UTC
+++ librocketchat.c
@@ -108,7 +108,7 @@ g_str_insensitive_hash(gconstpointer v)
 #ifndef ROCKETCHAT_PLUGIN_VERSION
 #define ROCKETCHAT_PLUGIN_VERSION "0.1"
 #endif
-#define ROCKETCHAT_PLUGIN_WEBSITE "https://bitbucket.org/EionRobb/purple-rocketchat"
+#define ROCKETCHAT_PLUGIN_WEBSITE "https://github.com/EionRobb/purple-rocketchat"
 
 #define ROCKETCHAT_USERAGENT "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36"
 
@@ -2406,7 +2406,7 @@ rc_socket_got_data(gpointer userdata, PurpleSslConnect
 					return;
 				} else if (ya->packet_code == 137) {
 					// Ping
-					gint ping_frame_len;
+					gint ping_frame_len = 0;
 					length_code = 0;
 					purple_ssl_read(conn, &length_code, 1);
 					if (length_code <= 125) {
@@ -3444,7 +3444,7 @@ rc_got_avatar(RocketChatAccount *ya, JsonNode *node, g
 		
 		response_str = g_dataset_get_data(node, "raw_body");
 		response_len = json_object_get_int_member(response, "len");
-		response_dup = g_memdup(response_str, response_len);
+		response_dup = g_memdup2(response_str, response_len);
 		
 		purple_buddy_icons_set_for_user(ya->account, purple_buddy_get_name(buddy), response_dup, response_len, NULL);
 	}
