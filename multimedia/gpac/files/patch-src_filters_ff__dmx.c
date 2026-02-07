--- src/filters/ff_dmx.c.orig	2024-04-17 17:18:21 UTC
+++ src/filters/ff_dmx.c
@@ -1255,9 +1255,15 @@ GF_Err ffdmx_init_common(GF_Filter *filter, GF_FFDemux
 		}
 		gf_filter_pid_set_property(pid, GF_PROP_PID_MUX_INDEX, &PROP_UINT(i+1));
 
+#if (LIBAVFORMAT_VERSION_MAJOR < 62)
 		for (j=0; j<(u32) stream->nb_side_data; j++) {
 			ffdmx_parse_side_data(&stream->side_data[j], pid);
 		}
+#else
+		for (j=0; j<(u32) stream->codecpar->nb_coded_side_data; j++) {
+			ffdmx_parse_side_data(&stream->codecpar->coded_side_data[j], pid);
+		}
+#endif
 
 		if (ctx->demuxer->nb_chapters) {
 			GF_PropertyValue p;
