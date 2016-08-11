--- xbmc/cores/AudioEngine/Sinks/AESinkOSS.cpp.orig	2016-02-20 15:21:19 UTC
+++ xbmc/cores/AudioEngine/Sinks/AESinkOSS.cpp
@@ -289,6 +289,8 @@ bool CAESinkOSS::Initialize(AEAudioForma
 #endif
 
   int tmp = (CAEUtil::DataFormatToBits(format.m_dataFormat) >> 3) * format.m_channelLayout.Count() * OSS_FRAMES;
+  if (AE_IS_RAW_HD(format.m_dataFormat) && m_initFormat.m_dataFormat != AE_FMT_LPCM)
+    tmp *= 8;
   int pos = 0;
   while ((tmp & 0x1) == 0x0)
   {
