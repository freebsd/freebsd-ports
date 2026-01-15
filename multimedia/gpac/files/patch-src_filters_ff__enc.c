--- src/filters/ff_enc.c.orig	2024-04-17 17:18:21 UTC
+++ src/filters/ff_enc.c
@@ -588,12 +588,25 @@ static GF_Err ffenc_process_video(GF_Filter *filter, s
 		}
 		if (pck) {
 			ilaced = gf_filter_pck_get_interlaced(pck);
+#if (LIBAVFORMAT_VERSION_MAJOR < 62)
 			if (!ilaced) {
 				ctx->frame->interlaced_frame = 0;
 			} else {
 				ctx->frame->interlaced_frame = 1;
 				ctx->frame->top_field_first = (ilaced==2) ? 1 : 0;
 			}
+#else
+			if (!ilaced) {
+				ctx->frame->flags &= ~AV_FRAME_FLAG_INTERLACED;
+			} else {
+				ctx->frame->flags |= AV_FRAME_FLAG_INTERLACED;
+				if (ilaced==2) {
+					ctx->frame->flags |= AV_FRAME_FLAG_TOP_FIELD_FIRST;
+				} else {
+					ctx->frame->flags &= ~AV_FRAME_FLAG_TOP_FIELD_FIRST;
+				}
+			}
+#endif
 			ctx->frame->pts = ffenc_get_cts(ctx, pck);
 			ctx->frame->_avf_dur = gf_filter_pck_get_duration(pck);
 		}
@@ -706,7 +719,7 @@ static GF_Err ffenc_process_video(GF_Filter *filter, s
 				ctx->reconfig_pending = GF_FALSE;
 				ctx->force_reconfig = GF_FALSE;
 				GF_LOG(GF_LOG_DEBUG, GF_LOG_CODEC, ("[FFEnc] codec flush done, triggering reconfiguration\n"));
-				avcodec_close(ctx->encoder);
+				avcodec_free_context(&ctx->encoder);
 				ctx->encoder = NULL;
 				ctx->setup_failed = 0;
 				e = ffenc_configure_pid_ex(filter, ctx->in_pid, GF_FALSE, GF_TRUE);
