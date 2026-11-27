--- vod/parse_utils.c.orig	2026-11-27 10:50:00 UTC
+++ vod/parse_utils.c
@@ -177,6 +177,11 @@ parse_utils_extract_track_tokens(u_char* start_pos, u_
 		if (stream_index == 0) {
 			// no index => all streams of the media type
 			vod_track_mask_set_all_bits(result[media_type]);
+		} else if (stream_index > MAX_TRACK_COUNT) {
+			// the index arrives straight from the request and vod_set_bit
+			// would write past the mask; stop short of end_pos so that
+			// every caller treats the input as invalid
+			return start_pos;
 		} else {
 			vod_set_bit(result[media_type], stream_index - 1);
 		}
