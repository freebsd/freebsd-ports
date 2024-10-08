--- plugins/obs-outputs/flv-mux.c.orig	2024-08-15 21:53:35 UTC
+++ plugins/obs-outputs/flv-mux.c
@@ -656,7 +656,7 @@ void flv_packet_metadata(enum video_id_t codec_id, uin
 	 * The default trackId is 0.
 	 */
 	if (is_multitrack) {
-		s_w8(&s, MULTITRACKTYPE_ONE_TRACK | PACKETTYPE_METADATA);
+		s_w8(&s, (uint8_t)MULTITRACKTYPE_ONE_TRACK | (uint8_t)PACKETTYPE_METADATA);
 		s_w4cc(&s, codec_id);
 		// trackId
 		s_w8(&s, (uint8_t)idx);
