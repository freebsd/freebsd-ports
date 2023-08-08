--- librocketchat.c.orig	2022-12-12 06:20:44 UTC
+++ librocketchat.c
@@ -2484,7 +2484,7 @@ rc_socket_got_data(gpointer userdata, PurpleSslConnect
 					return;
 				} else if (ya->packet_code == 137) {
 					// Ping
-					gint ping_frame_len;
+					gint ping_frame_len = 0;
 					length_code = 0;
 					purple_ssl_read(conn, &length_code, 1);
 					if (length_code <= 125) {
@@ -3518,7 +3518,7 @@ rc_got_avatar(RocketChatAccount *ya, JsonNode *node, g
 		
 		response_str = g_dataset_get_data(node, "raw_body");
 		response_len = json_object_get_int_member(response, "len");
-		response_dup = g_memdup(response_str, response_len);
+		response_dup = g_memdup2(response_str, response_len);
 		
 		purple_buddy_icons_set_for_user(ya->account, purple_buddy_get_name(buddy), response_dup, response_len, NULL);
 	}
