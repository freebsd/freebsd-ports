--- spa/include/spa/param/audio/dsd-utils.h.orig	2026-03-16 11:54:17 UTC
+++ spa/include/spa/param/audio/dsd-utils.h
@@ -44,7 +44,7 @@ spa_format_audio_dsd_parse(const struct spa_pod *forma
 			SPA_FORMAT_AUDIO_channels,	SPA_POD_OPT_Int(&info->channels),
 			SPA_FORMAT_AUDIO_position,	SPA_POD_OPT_Pod(&position));
 	if (info->channels > max_position)
-		return -ECHRNG;
+		return -EINVAL;
 	if (position == NULL ||
 	    spa_pod_copy_array(position, SPA_TYPE_Id, info->position, max_position) != info->channels) {
 		SPA_FLAG_SET(info->flags, SPA_AUDIO_FLAG_UNPOSITIONED);
