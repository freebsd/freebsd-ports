encoderColorFormat was added after 1.3.0, so omit it for now.

../gstsvthevcenc.c:732:15: error: no member named 'encoderColorFormat' in 'struct EB_H265_ENC_CONFIGURATION'
  svt_config->encoderColorFormat = EB_YUV420;
  ~~~~~~~~~~  ^
../gstsvthevcenc.c:732:36: error: use of undeclared identifier 'EB_YUV420'
  svt_config->encoderColorFormat = EB_YUV420;
                                   ^

--- gstsvthevcenc.c.orig	2019-03-27 13:22:12 UTC
+++ gstsvthevcenc.c
@@ -729,7 +729,6 @@ set_default_svt_configuration (EB_H265_ENC_CONFIGURATI
   svt_config->recoveryPointSeiFlag = FALSE;
   svt_config->enableTemporalId = 1;
   svt_config->encoderBitDepth = 8;
-  svt_config->encoderColorFormat = EB_YUV420;
   svt_config->compressedTenBitFormat = FALSE;
   svt_config->profile = 1;
   svt_config->tier = 0;
