--- libavcodec/libsvtav1.c.orig	2025-05-17 13:52:31 UTC
+++ libavcodec/libsvtav1.c
@@ -60,17 +60,20 @@ typedef struct SvtContext {
     EOS_STATUS eos_flag;
 
     // User options.
+    AVDictionary *svtav1_opts;
+#if FF_API_SVTAV1_OPTS
     int hierarchical_level;
     int la_depth;
-    int enc_mode;
-    int rc_mode;
     int scd;
-    int qp;
 
     int tier;
 
     int tile_columns;
     int tile_rows;
+#endif
+    int enc_mode;
+    int crf;
+    int qp;
 } SvtContext;
 
 static const struct {
@@ -147,11 +150,136 @@ static int config_enc_params(EbSvtAv1EncConfiguration 
 {
     SvtContext *svt_enc = avctx->priv_data;
     const AVPixFmtDescriptor *desc;
+    AVDictionaryEntry *en = NULL;
 
+    // Update param from options
+#if FF_API_SVTAV1_OPTS
+    if (svt_enc->hierarchical_level >= 0)
+        param->hierarchical_levels    = svt_enc->hierarchical_level;
+    if (svt_enc->tier >= 0)
+        param->tier                   = svt_enc->tier;
+    if (svt_enc->scd >= 0)
+        param->scene_change_detection = svt_enc->scd;
+    if (svt_enc->tile_columns >= 0)
+        param->tile_columns           = svt_enc->tile_columns;
+    if (svt_enc->tile_rows >= 0)
+        param->tile_rows              = svt_enc->tile_rows;
+
+    if (svt_enc->la_depth >= 0)
+        param->look_ahead_distance    = svt_enc->la_depth;
+#endif
+
+    if (svt_enc->enc_mode >= 0)
+        param->enc_mode             = svt_enc->enc_mode;
+
+    if (avctx->bit_rate) {
+        param->target_bit_rate      = avctx->bit_rate;
+        if (avctx->rc_max_rate != avctx->bit_rate)
+            param->rate_control_mode = 1;
+        else
+            param->rate_control_mode = 2;
+
+        param->max_qp_allowed       = avctx->qmax;
+        param->min_qp_allowed       = avctx->qmin;
+    }
+    param->max_bit_rate             = avctx->rc_max_rate;
+    if (avctx->bit_rate && avctx->rc_buffer_size)
+        param->maximum_buffer_size_ms = avctx->rc_buffer_size * 1000LL / avctx->bit_rate;
+
+    if (svt_enc->crf > 0) {
+        param->qp                   = svt_enc->crf;
+        param->rate_control_mode    = 0;
+    } else if (svt_enc->qp > 0) {
+        param->qp                   = svt_enc->qp;
+        param->rate_control_mode    = 0;
+#if SVT_AV1_CHECK_VERSION(4, 0, 0)
+        param->aq_mode = 0;
+#else
+        param->enable_adaptive_quantization = 0;
+#endif
+    }
+
+    desc = av_pix_fmt_desc_get(avctx->pix_fmt);
+    param->color_primaries          = avctx->color_primaries;
+    param->matrix_coefficients      = (desc->flags & AV_PIX_FMT_FLAG_RGB) ?
+                                      AVCOL_SPC_RGB : avctx->colorspace;
+    param->transfer_characteristics = avctx->color_trc;
+
+    if (avctx->color_range != AVCOL_RANGE_UNSPECIFIED)
+        param->color_range = avctx->color_range == AVCOL_RANGE_JPEG;
+    else
+        param->color_range = !!(desc->flags & AV_PIX_FMT_FLAG_RGB);
+
+#if SVT_AV1_CHECK_VERSION(1, 0, 0)
+    if (avctx->chroma_sample_location != AVCHROMA_LOC_UNSPECIFIED) {
+        const char *name =
+            av_chroma_location_name(avctx->chroma_sample_location);
+
+        switch (avctx->chroma_sample_location) {
+        case AVCHROMA_LOC_LEFT:
+            param->chroma_sample_position = EB_CSP_VERTICAL;
+            break;
+        case AVCHROMA_LOC_TOPLEFT:
+            param->chroma_sample_position = EB_CSP_COLOCATED;
+            break;
+        default:
+            if (!name)
+                break;
+
+            av_log(avctx, AV_LOG_WARNING,
+                   "Specified chroma sample location %s is unsupported "
+                   "on the AV1 bit stream level. Usage of a container that "
+                   "allows passing this information - such as Matroska - "
+                   "is recommended.\n",
+                   name);
+            break;
+        }
+    }
+#endif
+
+    if (avctx->profile != FF_PROFILE_UNKNOWN)
+        param->profile = avctx->profile;
+
+    if (avctx->level != FF_LEVEL_UNKNOWN)
+        param->level = avctx->level;
+
+    if (avctx->gop_size > 0)
+        param->intra_period_length  = avctx->gop_size - 1;
+
+    if (avctx->framerate.num > 0 && avctx->framerate.den > 0) {
+        param->frame_rate_numerator   = avctx->framerate.num;
+        param->frame_rate_denominator = avctx->framerate.den;
+    } else {
+        param->frame_rate_numerator   = avctx->time_base.den;
+        param->frame_rate_denominator = avctx->time_base.num * avctx->ticks_per_frame;
+    }
+
+    /* 2 = IDR, closed GOP, 1 = CRA, open GOP */
+    param->intra_refresh_type = avctx->flags & AV_CODEC_FLAG_CLOSED_GOP ? 2 : 1;
+
+#if SVT_AV1_CHECK_VERSION(0, 9, 1)
+    while ((en = av_dict_get(svt_enc->svtav1_opts, "", en, AV_DICT_IGNORE_SUFFIX))) {
+        EbErrorType ret = svt_av1_enc_parse_parameter(param, en->key, en->value);
+        if (ret != EB_ErrorNone) {
+            int level = (avctx->err_recognition & AV_EF_EXPLODE) ? AV_LOG_ERROR : AV_LOG_WARNING;
+            av_log(avctx, level, "Error parsing option %s: %s.\n", en->key, en->value);
+            if (avctx->err_recognition & AV_EF_EXPLODE)
+                return AVERROR(EINVAL);
+        }
+    }
+#else
+    if ((en = av_dict_get(svt_enc->svtav1_opts, "", NULL, AV_DICT_IGNORE_SUFFIX))) {
+        int level = (avctx->err_recognition & AV_EF_EXPLODE) ? AV_LOG_ERROR : AV_LOG_WARNING;
+        av_log(avctx, level, "svt-params needs libavcodec to be compiled with SVT-AV1 "
+                             "headers >= 0.9.1.\n");
+        if (avctx->err_recognition & AV_EF_EXPLODE)
+            return AVERROR(ENOSYS);
+    }
+#endif
+
     param->source_width     = avctx->width;
     param->source_height    = avctx->height;
 
-    desc = av_pix_fmt_desc_get(avctx->pix_fmt);
     param->encoder_bit_depth = desc->comp[0].depth;
 
     if (desc->log2_chroma_w == 1 && desc->log2_chroma_h == 1)
@@ -165,12 +293,6 @@ static int config_enc_params(EbSvtAv1EncConfiguration 
         return AVERROR(EINVAL);
     }
 
-    if (avctx->profile != FF_PROFILE_UNKNOWN)
-        param->profile = avctx->profile;
-
-    if (avctx->level != FF_LEVEL_UNKNOWN)
-        param->level = avctx->level;
-
     if ((param->encoder_color_format == EB_YUV422 || param->encoder_bit_depth > 10)
          && param->profile != FF_PROFILE_AV1_PROFESSIONAL ) {
         av_log(avctx, AV_LOG_WARNING, "Forcing Professional profile\n");
@@ -180,40 +302,21 @@ static int config_enc_params(EbSvtAv1EncConfiguration 
         param->profile = FF_PROFILE_AV1_HIGH;
     }
 
-    // Update param from options
-    param->hierarchical_levels      = svt_enc->hierarchical_level;
-    param->enc_mode                 = svt_enc->enc_mode;
-    param->tier                     = svt_enc->tier;
-    param->rate_control_mode        = svt_enc->rc_mode;
-    param->scene_change_detection   = svt_enc->scd;
-    param->qp                       = svt_enc->qp;
+    avctx->bit_rate       = param->rate_control_mode > 0 ?
+                            param->target_bit_rate : 0;
+    avctx->rc_max_rate    = param->max_bit_rate;
+    avctx->rc_buffer_size = param->maximum_buffer_size_ms * avctx->bit_rate / 1000LL;
 
-    param->target_bit_rate          = avctx->bit_rate;
+    if (avctx->bit_rate || avctx->rc_max_rate || avctx->rc_buffer_size) {
+        AVCPBProperties *cpb_props = ff_add_cpb_side_data(avctx);
+        if (!cpb_props)
+            return AVERROR(ENOMEM);
 
-    if (avctx->gop_size > 0)
-        param->intra_period_length  = avctx->gop_size - 1;
-
-    if (avctx->framerate.num > 0 && avctx->framerate.den > 0) {
-        param->frame_rate_numerator   = avctx->framerate.num;
-        param->frame_rate_denominator = avctx->framerate.den;
-    } else {
-        param->frame_rate_numerator   = avctx->time_base.den;
-        param->frame_rate_denominator = avctx->time_base.num * avctx->ticks_per_frame;
+        cpb_props->buffer_size = avctx->rc_buffer_size;
+        cpb_props->max_bitrate = avctx->rc_max_rate;
+        cpb_props->avg_bitrate = avctx->bit_rate;
     }
 
-    if (param->rate_control_mode) {
-        param->max_qp_allowed       = avctx->qmax;
-        param->min_qp_allowed       = avctx->qmin;
-    }
-
-    param->intra_refresh_type       = 2; /* Real keyframes only */
-
-    if (svt_enc->la_depth >= 0)
-        param->look_ahead_distance  = svt_enc->la_depth;
-
-    param->tile_columns = svt_enc->tile_columns;
-    param->tile_rows    = svt_enc->tile_rows;
-
     return 0;
 }
 
@@ -262,7 +365,7 @@ static av_cold int eb_enc_init(AVCodecContext *avctx)
 
     svt_enc->eos_flag = EOS_NOT_REACHED;
 
-    svt_ret = svt_av1_enc_init_handle(&svt_enc->svt_handle, svt_enc, &svt_enc->enc_params);
+    svt_ret = svt_av1_enc_init_handle(&svt_enc->svt_handle, &svt_enc->enc_params);
     if (svt_ret != EB_ErrorNone) {
         return svt_print_error(avctx, svt_ret, "Error initializing encoder handle");
     }
@@ -326,11 +429,8 @@ static int eb_send_frame(AVCodecContext *avctx, const 
         if (svt_enc->eos_flag == EOS_SENT)
             return 0;
 
-        headerPtrLast.n_alloc_len   = 0;
-        headerPtrLast.n_filled_len  = 0;
-        headerPtrLast.n_tick_count  = 0;
-        headerPtrLast.p_app_private = NULL;
-        headerPtrLast.p_buffer      = NULL;
+        memset(&headerPtrLast, 0, sizeof(headerPtrLast));
+        headerPtrLast.pic_type      = EB_AV1_INVALID_PICTURE;
         headerPtrLast.flags         = EB_BUFFERFLAG_EOS;
 
         svt_av1_enc_send_picture(svt_enc->svt_handle, &headerPtrLast);
@@ -346,6 +446,16 @@ static int eb_send_frame(AVCodecContext *avctx, const 
     headerPtr->p_app_private = NULL;
     headerPtr->pts           = frame->pts;
 
+    switch (frame->pict_type) {
+    case AV_PICTURE_TYPE_I:
+        headerPtr->pic_type = EB_AV1_KEY_PICTURE;
+        break;
+    default:
+        // Actually means auto, or default.
+        headerPtr->pic_type = EB_AV1_INVALID_PICTURE;
+        break;
+    }
+
     svt_av1_enc_send_picture(svt_enc->svt_handle, headerPtr);
 
     return 0;
@@ -468,21 +578,22 @@ static const AVOption options[] = {
 #define OFFSET(x) offsetof(SvtContext, x)
 #define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
 static const AVOption options[] = {
-    { "hielevel", "Hierarchical prediction levels setting", OFFSET(hierarchical_level),
-      AV_OPT_TYPE_INT, { .i64 = 4 }, 3, 4, VE , "hielevel"},
+#if FF_API_SVTAV1_OPTS
+    { "hielevel", "Hierarchical prediction levels setting (Deprecated, use svtav1-params)", OFFSET(hierarchical_level),
+      AV_OPT_TYPE_INT, { .i64 = -1 }, -1, 4, VE | AV_OPT_FLAG_DEPRECATED , "hielevel"},
         { "3level", NULL, 0, AV_OPT_TYPE_CONST, { .i64 = 3 },  INT_MIN, INT_MAX, VE, "hielevel" },
         { "4level", NULL, 0, AV_OPT_TYPE_CONST, { .i64 = 4 },  INT_MIN, INT_MAX, VE, "hielevel" },
 
-    { "la_depth", "Look ahead distance [0, 120]", OFFSET(la_depth),
-      AV_OPT_TYPE_INT, { .i64 = -1 }, -1, 120, VE },
+    { "la_depth", "Look ahead distance [0, 120] (Deprecated, use svtav1-params)", OFFSET(la_depth),
+      AV_OPT_TYPE_INT, { .i64 = -1 }, -1, 120, VE | AV_OPT_FLAG_DEPRECATED },
 
-    { "preset", "Encoding preset [0, 8]",
-      OFFSET(enc_mode), AV_OPT_TYPE_INT, { .i64 = MAX_ENC_PRESET }, 0, MAX_ENC_PRESET, VE },
-
-    { "tier", "Set operating point tier", OFFSET(tier),
-      AV_OPT_TYPE_INT, { .i64 = 0 }, 0, 1, VE, "tier" },
+    { "tier", "Set operating point tier (Deprecated, use svtav1-params)", OFFSET(tier),
+      AV_OPT_TYPE_INT, { .i64 = -1 }, -1, 1, VE | AV_OPT_FLAG_DEPRECATED, "tier" },
         { "main", NULL, 0, AV_OPT_TYPE_CONST, { .i64 = 0 }, 0, 0, VE, "tier" },
         { "high", NULL, 0, AV_OPT_TYPE_CONST, { .i64 = 1 }, 0, 0, VE, "tier" },
+#endif
+    { "preset", "Encoding preset",
+      OFFSET(enc_mode), AV_OPT_TYPE_INT, { .i64 = -1 }, -1, MAX_ENC_PRESET, VE },
 
     FF_AV1_PROFILE_OPTS
 
@@ -514,21 +625,20 @@ static const AVOption options[] = {
         { LEVEL("7.3", 73) },
 #undef LEVEL
 
-    { "rc", "Bit rate control mode", OFFSET(rc_mode),
-      AV_OPT_TYPE_INT, { .i64 = 0 }, 0, 3, VE , "rc"},
-        { "cqp", "Constant quantizer", 0, AV_OPT_TYPE_CONST, { .i64 = 0 },  INT_MIN, INT_MAX, VE, "rc" },
-        { "vbr", "Variable Bit Rate, use a target bitrate for the entire stream", 0, AV_OPT_TYPE_CONST, { .i64 = 1 },  INT_MIN, INT_MAX, VE, "rc" },
-        { "cvbr", "Constrained Variable Bit Rate, use a target bitrate for each GOP", 0, AV_OPT_TYPE_CONST,{ .i64 = 2 },  INT_MIN, INT_MAX, VE, "rc" },
+    { "crf", "Constant Rate Factor value", OFFSET(crf),
+      AV_OPT_TYPE_INT, { .i64 = 0 }, 0, 63, VE },
+    { "qp", "Initial Quantizer level value", OFFSET(qp),
+      AV_OPT_TYPE_INT, { .i64 = 0 }, 0, 63, VE },
+#if FF_API_SVTAV1_OPTS
+    { "sc_detection", "Scene change detection (Deprecated, use svtav1-params)", OFFSET(scd),
+      AV_OPT_TYPE_BOOL, { .i64 = -1 }, -1, 1, VE | AV_OPT_FLAG_DEPRECATED },
 
-    { "qp", "Quantizer to use with cqp rate control mode", OFFSET(qp),
-      AV_OPT_TYPE_INT, { .i64 = 50 }, 0, 63, VE },
+    { "tile_columns", "Log2 of number of tile columns to use (Deprecated, use svtav1-params)", OFFSET(tile_columns), AV_OPT_TYPE_INT, { .i64 = -1 }, -1, 4, VE | AV_OPT_FLAG_DEPRECATED },
+    { "tile_rows", "Log2 of number of tile rows to use (Deprecated, use svtav1-params)", OFFSET(tile_rows), AV_OPT_TYPE_INT, { .i64 = -1 }, -1, 6, VE | AV_OPT_FLAG_DEPRECATED },
+#endif
 
-    { "sc_detection", "Scene change detection", OFFSET(scd),
-      AV_OPT_TYPE_BOOL, { .i64 = 0 }, 0, 1, VE },
+    { "svtav1-params", "Set the SVT-AV1 configuration using a :-separated list of key=value parameters", OFFSET(svtav1_opts), AV_OPT_TYPE_DICT, { 0 }, 0, 0, VE },
 
-    { "tile_columns", "Log2 of number of tile columns to use", OFFSET(tile_columns), AV_OPT_TYPE_INT, {.i64 = 0}, 0, 4, VE},
-    { "tile_rows", "Log2 of number of tile rows to use", OFFSET(tile_rows), AV_OPT_TYPE_INT, {.i64 = 0}, 0, 6, VE},
-
     {NULL},
 };
 
@@ -540,9 +650,10 @@ static const AVCodecDefault eb_enc_defaults[] = {
 };
 
 static const AVCodecDefault eb_enc_defaults[] = {
-    { "b",         "7M"    },
+    { "b",         "0"    },
+    { "flags",     "+cgop" },
     { "g",         "-1"    },
-    { "qmin",      "0"     },
+    { "qmin",      "1"     },
     { "qmax",      "63"    },
     { NULL },
 };
@@ -557,12 +668,11 @@ AVCodec ff_libsvtav1_encoder = {
     .receive_packet = eb_receive_packet,
     .close          = eb_enc_close,
     .capabilities   = AV_CODEC_CAP_DELAY | AV_CODEC_CAP_OTHER_THREADS,
-    .caps_internal  = FF_CODEC_CAP_AUTO_THREADS,
+    .caps_internal  = FF_CODEC_CAP_AUTO_THREADS | FF_CODEC_CAP_INIT_CLEANUP,
     .pix_fmts       = (const enum AVPixelFormat[]){ AV_PIX_FMT_YUV420P,
                                                     AV_PIX_FMT_YUV420P10,
                                                     AV_PIX_FMT_NONE },
     .priv_class     = &class,
     .defaults       = eb_enc_defaults,
-    .caps_internal  = FF_CODEC_CAP_INIT_CLEANUP,
     .wrapper_name   = "libsvtav1",
 };
