--- spa/include/spa/param/audio/raw-json.h.orig	2026-03-16 11:54:17 UTC
+++ spa/include/spa/param/audio/raw-json.h
@@ -88,14 +88,14 @@ spa_audio_info_raw_ext_update(struct spa_audio_info_ra
 	} else if (spa_streq(key, SPA_KEY_AUDIO_CHANNELS)) {
 		if (spa_atou32(val, &v, 0) && (force || info->channels == 0)) {
 			if (v > max_position)
-				return -ECHRNG;
+				return -EINVAL;
 			info->channels = v;
 		}
 	} else if (spa_streq(key, SPA_KEY_AUDIO_LAYOUT)) {
 		if (force || info->channels == 0) {
 			if (spa_audio_parse_layout(val, info->position, max_position, &v) > 0) {
 				if (v > max_position)
-					return -ECHRNG;
+					return -EINVAL;
 				info->channels = v;
 				SPA_FLAG_CLEAR(info->flags, SPA_AUDIO_FLAG_UNPOSITIONED);
 			}
@@ -105,7 +105,7 @@ spa_audio_info_raw_ext_update(struct spa_audio_info_ra
 			if (spa_audio_parse_position_n(val, strlen(val), info->position,
 						max_position, &v) > 0) {
 				if (v > max_position)
-					return -ECHRNG;
+					return -EINVAL;
 				info->channels = v;
 				SPA_FLAG_CLEAR(info->flags, SPA_AUDIO_FLAG_UNPOSITIONED);
 			}
