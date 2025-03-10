--- libhb/enc_qsv.c.orig	2024-12-01 15:28:40 UTC
+++ libhb/enc_qsv.c
@@ -174,7 +174,9 @@ static int log_encoder_params(const hb_work_private_t 
 {
     const mfxExtCodingOption  *option1 = NULL;
     const mfxExtCodingOption2 *option2 = NULL;
+#if (MFX_VERSION >= 2012)
     const mfxExtAV1ScreenContentTools *extScreenContentCoding = NULL;
+#endif
     const mfxExtHyperModeParam *extHyperModeOption = NULL;
 
     for (int i = 0; i < videoParam->NumExtParam; i++)
@@ -188,10 +190,12 @@ static int log_encoder_params(const hb_work_private_t 
         {
             option2 = (mfxExtCodingOption2*)videoParam->ExtParam[i];
         }
+#if (MFX_VERSION >= 2012)
         else if (option->Header.BufferId == MFX_EXTBUFF_AV1_SCREEN_CONTENT_TOOLS)
         {
             extScreenContentCoding = (mfxExtAV1ScreenContentTools*)videoParam->ExtParam[i];
         }
+#endif
         else if (option->Header.BufferId == MFX_EXTBUFF_HYPER_MODE_PARAM)
         {
             extHyperModeOption = (mfxExtHyperModeParam*)videoParam->ExtParam[i];
@@ -221,13 +225,14 @@ static int log_encoder_params(const hb_work_private_t 
     hb_log("encqsvInit: GopRefDist %"PRIu16" GopPicSize %"PRIu16" NumRefFrame %"PRIu16" IdrInterval %"PRIu16"",
            videoParam->mfx.GopRefDist, videoParam->mfx.GopPicSize, videoParam->mfx.NumRefFrame, videoParam->mfx.IdrInterval);
 
+#if (MFX_VERSION >= 2012)
     if (extScreenContentCoding && ((extScreenContentCoding->IntraBlockCopy == MFX_CODINGOPTION_ON) || (extScreenContentCoding->Palette == MFX_CODINGOPTION_ON)))
     {
         hb_log("encqsvInit: ScreenContentCoding is enabled IBC %s, Palette %s",
             (extScreenContentCoding->IntraBlockCopy == MFX_CODINGOPTION_ON) ? "on" : "off",
             (extScreenContentCoding->Palette == MFX_CODINGOPTION_ON) ? "on" : "off");
     }
-
+#endif
     if (pv->qsv_info->capabilities & HB_QSV_CAP_B_REF_PYRAMID)
     {
         hb_log("encqsvInit: BFramesMax %d BRefType %s",
@@ -1670,7 +1675,9 @@ int encqsvInit(hb_work_object_t *w, hb_job_t *job)
     mfxSession session = (mfxSession)0;
     mfxExtCodingOption  option1_buf, *option1 = &option1_buf;
     mfxExtCodingOption2 option2_buf, *option2 = &option2_buf;
+#if (MFX_VERSION >= 2012)
     mfxExtAV1ScreenContentTools screencont_coding_buf, *screencont_coding = &screencont_coding_buf;
+#endif
     mfxExtCodingOptionSPSPPS sps_pps_buf, *sps_pps = &sps_pps_buf;
     mfxExtAV1BitstreamParam av1_bitstream_buf, *av1_bitstream = &av1_bitstream_buf;
     mfxExtChromaLocInfo chroma_loc_info_buf, *chroma_loc_info = &chroma_loc_info_buf;
@@ -1795,6 +1802,7 @@ int encqsvInit(hb_work_object_t *w, hb_job_t *job)
     {
         videoParam.ExtParam[videoParam.NumExtParam++] = (mfxExtBuffer*)hyper_encode;
     }
+#if (MFX_VERSION >= 2012)
     memset(screencont_coding, 0, sizeof(mfxExtAV1ScreenContentTools));
     screencont_coding->Header.BufferId = MFX_EXTBUFF_AV1_SCREEN_CONTENT_TOOLS;
     screencont_coding->Header.BufferSz = sizeof(mfxExtAV1ScreenContentTools);
@@ -1802,6 +1810,7 @@ int encqsvInit(hb_work_object_t *w, hb_job_t *job)
     {
         videoParam.ExtParam[videoParam.NumExtParam++] = (mfxExtBuffer*)screencont_coding;
     }
+#endif
     /* Query actual encoding parameters after MFXVideoENCODE_Init, some of them could be overridden */
     sts = MFXVideoENCODE_GetVideoParam(session, &videoParam);
     if (sts != MFX_ERR_NONE)
