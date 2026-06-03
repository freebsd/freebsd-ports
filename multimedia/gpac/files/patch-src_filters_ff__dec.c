--- src/filters/ff_dec.c.orig	2024-04-17 17:18:21 UTC
+++ src/filters/ff_dec.c
@@ -535,8 +535,13 @@ restart:
 
 	gf_filter_pck_set_seek_flag(dst_pck, GF_FALSE);
 
+#if (LIBAVFORMAT_VERSION_MAJOR < 62)
 	if (frame->interlaced_frame)
 		gf_filter_pck_set_interlaced(dst_pck, frame->top_field_first ? 2 : 1);
+#else
+	if (frame->flags & AV_FRAME_FLAG_INTERLACED)
+		gf_filter_pck_set_interlaced(dst_pck, frame->flags & AV_FRAME_FLAG_TOP_FIELD_FIRST ? 2 : 1);
+#endif
 
 	gf_filter_pck_send(dst_pck);
 
