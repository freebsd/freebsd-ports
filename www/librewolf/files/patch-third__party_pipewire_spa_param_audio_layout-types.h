commit 52803d9c34299eafd54a50dcf70be63db35ce593
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    use standard EINVAL instead of linux-only ECHRNG
    
    directly lifted from multimedia/pipewire

diff --git third_party/pipewire/spa/param/audio/layout-types.h third_party/pipewire/spa/param/audio/layout-types.h
index 33650202ab85..45cca3a6f335 100644
--- third_party/pipewire/spa/param/audio/layout-types.h
+++ third_party/pipewire/spa/param/audio/layout-types.h
@@ -87,7 +87,7 @@ spa_audio_layout_info_parse_name(struct spa_audio_layout_info *layout, size_t si
 		uint32_t i, n_pos;
 		if (spa_atou32(name+3, &n_pos, 10)) {
 			if (n_pos > max_position)
-				return -ECHRNG;
+				return -EINVAL;
 			for (i = 0; i < 0x1000 && i < n_pos; i++)
 				layout->position[i] = SPA_AUDIO_CHANNEL_AUX0 + i;
 			for (; i < n_pos; i++)
@@ -99,7 +99,7 @@ spa_audio_layout_info_parse_name(struct spa_audio_layout_info *layout, size_t si
 	SPA_FOR_EACH_ELEMENT_VAR(spa_type_audio_layout_info, i) {
 		if (spa_streq(name, i->name)) {
 			if (i->layout.n_channels > max_position)
-				return -ECHRNG;
+				return -EINVAL;
 			*layout = i->layout;
 			return i->layout.n_channels;
 		}
