--- xbmc/cores/AudioEngine/Engines/SoftAE/SoftAE.cpp.orig	2015-05-11 07:54:22 UTC
+++ xbmc/cores/AudioEngine/Engines/SoftAE/SoftAE.cpp
@@ -328,7 +328,7 @@ void CSoftAE::InternalOpenSink()
 
     /* perform basic sanity checks on the format returned by the sink */
     ASSERT(newFormat.m_channelLayout.Count() > 0);
-    ASSERT(newFormat.m_dataFormat           <= AE_FMT_FLOAT);
+    ASSERT(newFormat.m_dataFormat           <= AE_FMT_MAX);
     ASSERT(newFormat.m_frames                > 0);
     ASSERT(newFormat.m_frameSamples          > 0);
     ASSERT(newFormat.m_frameSize            == (CAEUtil::DataFormatToBits(newFormat.m_dataFormat) >> 3) * newFormat.m_channelLayout.Count());
