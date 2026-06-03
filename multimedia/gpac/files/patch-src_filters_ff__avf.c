--- src/filters/ff_avf.c.orig	2024-04-17 17:18:21 UTC
+++ src/filters/ff_avf.c
@@ -722,9 +722,13 @@ static GF_Err ffavf_process(GF_Filter *filter)
 					memcpy(buffer + j*opid->stride, frame->data[3] + j*frame->linesize[3], opid->width*opid->bpp);
 				}
 			}
+#if (LIBAVFORMAT_VERSION_MAJOR < 62)
 			if (frame->interlaced_frame)
 				gf_filter_pck_set_interlaced(pck, frame->top_field_first ? 1 : 2);
-
+#else
+			if (frame->flags & AV_FRAME_FLAG_INTERLACED)
+				gf_filter_pck_set_interlaced(pck, frame->flags & AV_FRAME_FLAG_TOP_FIELD_FIRST ? 1 : 2);
+#endif
 			gf_filter_pck_set_sap(pck, GF_FILTER_SAP_1);
 			gf_filter_pck_set_cts(pck, frame->pts * opid->tb_num);
 			gf_filter_pck_send(pck);
