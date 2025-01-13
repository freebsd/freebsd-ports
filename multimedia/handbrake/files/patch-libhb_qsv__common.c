--- libhb/qsv_common.c.orig	2024-12-01 15:28:40 UTC
+++ libhb/qsv_common.c
@@ -463,6 +463,7 @@ int qsv_map_mfx_platform_codename(int mfx_platform_cod
     case MFX_PLATFORM_DG2:
     case MFX_PLATFORM_ALDERLAKE_N:
     case MFX_PLATFORM_KEEMBAY:
+#if (MFX_VERSION >= 2012)
     case MFX_PLATFORM_METEORLAKE:
     case MFX_PLATFORM_BATTLEMAGE:
     case MFX_PLATFORM_ARROWLAKE:
@@ -471,6 +472,7 @@ int qsv_map_mfx_platform_codename(int mfx_platform_cod
     case MFX_PLATFORM_LUNARLAKE:
         platform = HB_CPU_PLATFORM_INTEL_LNL;
         break;
+#endif
     default:
         platform = HB_CPU_PLATFORM_UNSPECIFIED;
     }
@@ -984,7 +986,7 @@ static void init_ext_av1bitstream_option(mfxExtAV1Bits
     extAV1BitstreamParam->Header.BufferSz = sizeof(mfxExtAV1BitstreamParam);
     extAV1BitstreamParam->WriteIVFHeaders = MFX_CODINGOPTION_OFF;
 }
-
+#if (MFX_VERSION >= 2012)
 static void init_ext_av1screencontent_tools(mfxExtAV1ScreenContentTools *extScreenContentTools)
 {
     if (extScreenContentTools == NULL)
@@ -998,7 +1000,7 @@ static void init_ext_av1screencontent_tools(mfxExtAV1S
     extScreenContentTools->IntraBlockCopy  = MFX_CODINGOPTION_OFF;
     extScreenContentTools->Palette         = MFX_CODINGOPTION_OFF;
 }
-
+#endif
 static int query_capabilities(mfxSession session, int index, mfxVersion version, hb_qsv_info_t *info, int lowpower)
 {
     /*
@@ -1026,7 +1028,9 @@ static int query_capabilities(mfxSession session, int 
     mfxExtMasteringDisplayColourVolume  extMasteringDisplayColourVolume;
     mfxExtContentLightLevelInfo         extContentLightLevelInfo;
     mfxExtAV1BitstreamParam extAV1BitstreamParam;
+#if (MFX_VERSION >= 2012)
     mfxExtAV1ScreenContentTools extAV1ScreenContentToolsParam;
+#endif
     mfxExtHyperModeParam extHyperEncodeParam;
 
     /* Reset capabilities before querying */
@@ -1460,6 +1464,7 @@ static int query_capabilities(mfxSession session, int 
                 info->capabilities |= HB_QSV_CAP_HYPERENCODE;
             }
         }
+#if (MFX_VERSION >= 2012)
         if ((lowpower == MFX_CODINGOPTION_ON) && (info->codec_id == MFX_CODEC_AV1))
         {
             init_video_param(&videoParam);
@@ -1494,6 +1499,7 @@ static int query_capabilities(mfxSession session, int 
                 info->capabilities |= HB_QSV_CAP_AV1_SCREENCONTENT;
             }
         }
+#endif
     }
 
     return 0;
@@ -1935,10 +1941,12 @@ static void log_encoder_capabilities(const int log_lev
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
@@ -3011,6 +3019,7 @@ int hb_qsv_param_parse(hb_qsv_param_t *param, hb_qsv_i
             param->hyperEncodeParam.Mode = mode->value;
         }
     }
+#if (MFX_VERSION >= 2012)
     else if (!strcasecmp(key, "palette"))
     {
         if (info->capabilities & HB_QSV_CAP_AV1_SCREENCONTENT)
@@ -3041,6 +3050,7 @@ int hb_qsv_param_parse(hb_qsv_param_t *param, hb_qsv_i
             return HB_QSV_PARAM_UNSUPPORTED;
         }
     }
+#endif
     else if (!strcasecmp(key, "async-depth"))
     {
         int async_depth = hb_qsv_atoi(value, &error);
@@ -3527,13 +3537,14 @@ int hb_qsv_param_default(hb_qsv_param_t *param, mfxVid
         param->av1BitstreamParam.Header.BufferId = MFX_EXTBUFF_AV1_BITSTREAM_PARAM;
         param->av1BitstreamParam.Header.BufferSz = sizeof(mfxExtAV1BitstreamParam);
         param->av1BitstreamParam.WriteIVFHeaders = MFX_CODINGOPTION_OFF;
+#if (MFX_VERSION >= 2012)
         // introduced in API 2.11
         memset(&param->av1ScreenContentToolsParam, 0, sizeof(mfxExtAV1ScreenContentTools));
         param->av1ScreenContentToolsParam.Header.BufferId = MFX_EXTBUFF_AV1_SCREEN_CONTENT_TOOLS;
         param->av1ScreenContentToolsParam.Header.BufferSz = sizeof(mfxExtAV1ScreenContentTools);
         param->av1ScreenContentToolsParam.IntraBlockCopy  = MFX_CODINGOPTION_OFF;
         param->av1ScreenContentToolsParam.Palette         = MFX_CODINGOPTION_OFF;
-
+#endif
         // GOP & rate control
         param->gop.b_pyramid          =  1; // enabled by default (if supported)
         param->gop.gop_pic_size       = -1; // set automatically
@@ -3607,10 +3618,12 @@ int hb_qsv_param_default(hb_qsv_param_t *param, mfxVid
         {
             param->videoParam->ExtParam[param->videoParam->NumExtParam++] = (mfxExtBuffer*)&param->av1BitstreamParam;
         }
+#if (MFX_VERSION >= 2012)
         if (info->capabilities & HB_QSV_CAP_AV1_SCREENCONTENT)
         {
             param->videoParam->ExtParam[param->videoParam->NumExtParam++] = (mfxExtBuffer*)&param->av1ScreenContentToolsParam;
         }
+#endif
 #if defined(_WIN32) || defined(__MINGW32__)
         if (info->capabilities & HB_QSV_CAP_LOWPOWER_ENCODE)
         {
