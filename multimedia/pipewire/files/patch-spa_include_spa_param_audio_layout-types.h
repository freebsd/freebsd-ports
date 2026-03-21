--- spa/include/spa/param/audio/layout-types.h.orig	2026-03-16 11:54:17 UTC
+++ spa/include/spa/param/audio/layout-types.h
@@ -87,7 +87,7 @@ spa_audio_layout_info_parse_name(struct spa_audio_layo
 		uint32_t i, n_pos;
 		if (spa_atou32(name+3, &n_pos, 10)) {
 			if (n_pos > max_position)
-				return -ECHRNG;
+				return -EINVAL;
 			for (i = 0; i < 0x1000 && i < n_pos; i++)
 				layout->position[i] = SPA_AUDIO_CHANNEL_AUX0 + i;
 			for (; i < n_pos; i++)
@@ -99,7 +99,7 @@ spa_audio_layout_info_parse_name(struct spa_audio_layo
 	SPA_FOR_EACH_ELEMENT_VAR(spa_type_audio_layout_info, i) {
 		if (spa_streq(name, i->name)) {
 			if (i->layout.n_channels > max_position)
-				return -ECHRNG;
+				return -EINVAL;
 			*layout = i->layout;
 			return i->layout.n_channels;
 		}
