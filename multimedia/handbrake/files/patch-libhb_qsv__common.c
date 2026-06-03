--- libhb/qsv_common.c.orig	2025-08-08 16:41:24 UTC
+++ libhb/qsv_common.c
@@ -390,6 +390,7 @@ int qsv_map_mfx_platform_codename(int mfx_platform_cod
     case MFX_PLATFORM_DG2:
     case MFX_PLATFORM_ALDERLAKE_N:
     case MFX_PLATFORM_KEEMBAY:
+#if (MFX_VERSION >= 2012)
     case MFX_PLATFORM_METEORLAKE:
     case MFX_PLATFORM_BATTLEMAGE:
     case MFX_PLATFORM_ARROWLAKE:
@@ -398,6 +399,7 @@ int qsv_map_mfx_platform_codename(int mfx_platform_cod
     case MFX_PLATFORM_LUNARLAKE:
         platform = HB_CPU_PLATFORM_INTEL_LNL;
         break;
+#endif
     default:
         platform = HB_CPU_PLATFORM_UNSPECIFIED;
     }
@@ -928,6 +930,7 @@ static void init_ext_coding_option2(mfxExtCodingOption
     extCodingOption2->NumMbPerSlice   = 2040; // 1920x1088/4
 }
 
+#if (MFX_VERSION >= 2012)
 static void init_ext_av1bitstream_option(mfxExtAV1BitstreamParam *extAV1BitstreamParam)
 {
     if (extAV1BitstreamParam == NULL)
@@ -954,6 +957,7 @@ static void init_ext_av1screencontent_tools(mfxExtAV1S
     extScreenContentTools->IntraBlockCopy  = MFX_CODINGOPTION_OFF;
     extScreenContentTools->Palette         = MFX_CODINGOPTION_OFF;
 }
+#endif
 
 static int query_capabilities(mfxSession session, int index, mfxVersion version, hb_qsv_info_t *info, int lowpower)
 {
@@ -981,8 +985,10 @@ static int query_capabilities(mfxSession session, int 
     mfxExtChromaLocInfo   extChromaLocInfo;
     mfxExtMasteringDisplayColourVolume  extMasteringDisplayColourVolume;
     mfxExtContentLightLevelInfo         extContentLightLevelInfo;
+#if (MFX_VERSION >= 2012)
     mfxExtAV1BitstreamParam extAV1BitstreamParam;
     mfxExtAV1ScreenContentTools extAV1ScreenContentToolsParam;
+#endif
     mfxExtHyperModeParam extHyperEncodeParam;
 
     /* Reset capabilities before querying */
@@ -1416,6 +1422,7 @@ static int query_capabilities(mfxSession session, int 
                 info->capabilities |= HB_QSV_CAP_HYPERENCODE;
             }
         }
+#if (MFX_VERSION >= 2012)
         if ((lowpower == MFX_CODINGOPTION_ON) && (info->codec_id == MFX_CODEC_AV1))
         {
             init_video_param(&videoParam);
@@ -1450,6 +1457,7 @@ static int query_capabilities(mfxSession session, int 
                 info->capabilities |= HB_QSV_CAP_AV1_SCREENCONTENT;
             }
         }
+#endif
     }
 
     return 0;
@@ -1891,10 +1899,12 @@ static void log_encoder_capabilities(const int log_lev
             strcat(buffer, "+nmpslice");
         }
     }
+#if (MFX_VERSION >= 2012)
     if (caps & HB_QSV_CAP_AV1_SCREENCONTENT)
     {
         strcat(buffer, " av1screencontent");
     }
+#endif
     if (caps & HB_QSV_CAP_HYPERENCODE)
     {
         strcat(buffer, " hyperencode");
@@ -2686,6 +2696,7 @@ int hb_qsv_select_ffmpeg_options(qsv_data_t * qsv_data
             hb_log("encavcodec: using Low Power mode");
     }
 
+#if (MFX_VERSION >= 2012)
     if((qsv_data->qsv_info->capabilities & HB_QSV_CAP_AV1_SCREENCONTENT) &&
         qsv_data->param.av1ScreenContentToolsParam.IntraBlockCopy)
     {
@@ -2705,6 +2716,7 @@ int hb_qsv_select_ffmpeg_options(qsv_data_t * qsv_data
         hb_log("encavcodec: ScreenContentCoding is enabled Palette %s",
             qsv_data->param.av1ScreenContentToolsParam.Palette ? "on" : "off");
     }
+#endif
 
   // Transcoding Info
   MFX_STRUCT_TO_AV_OPTS(BRCParamMultiplier)
@@ -3318,6 +3330,7 @@ int hb_qsv_param_parse(AVDictionary** av_opts, hb_qsv_
             param->hyperEncodeParam = mode;
         }
     }
+#if (MFX_VERSION >= 2012)
     else if (!strcasecmp(key, "palette"))
     {
         if (info->capabilities & HB_QSV_CAP_AV1_SCREENCONTENT)
@@ -3348,6 +3361,7 @@ int hb_qsv_param_parse(AVDictionary** av_opts, hb_qsv_
             return HB_QSV_PARAM_UNSUPPORTED;
         }
     }
+#endif
     else if (!strcasecmp(key, "async-depth"))
     {
         int async_depth = hb_qsv_atoi(value, &error);
@@ -3617,6 +3631,12 @@ int hb_qsv_param_default(hb_qsv_param_t *param, hb_qsv
         // introduced in API 2.5
         param->hyperEncodeParam              = hb_triplet4key(hb_qsv_hyper_encode_modes, "off");
 
+        memset(&param->av1BitstreamParam, 0, sizeof(mfxExtAV1BitstreamParam));
+        param->av1BitstreamParam.Header.BufferId = MFX_EXTBUFF_AV1_BITSTREAM_PARAM;
+        param->av1BitstreamParam.Header.BufferSz = sizeof(mfxExtAV1BitstreamParam);
+        param->av1BitstreamParam.WriteIVFHeaders = MFX_CODINGOPTION_OFF;
+
+#if (MFX_VERSION >= 2012)
         // introduced in API 2.11
         memset(&param->av1ScreenContentToolsParam, 0, sizeof(mfxExtAV1ScreenContentTools));
         param->av1ScreenContentToolsParam.Header.BufferId = MFX_EXTBUFF_AV1_SCREEN_CONTENT_TOOLS;
@@ -3639,6 +3659,7 @@ int hb_qsv_param_default(hb_qsv_param_t *param, hb_qsv
         param->rc.vbv_buffer_init     = .0; // set automatically
 
         param->low_power              = 0;
+#endif
 
 #if defined(_WIN32) || defined(__MINGW32__)
         if (info->capabilities & HB_QSV_CAP_LOWPOWER_ENCODE)
