diff --git xbmc/cores/AudioEngine/Engines/SoftAE/SoftAE.cpp xbmc/cores/AudioEngine/Engines/SoftAE/SoftAE.cpp
index bd01a67..49edfee 100644
--- xbmc/cores/AudioEngine/Engines/SoftAE/SoftAE.cpp
+++ xbmc/cores/AudioEngine/Engines/SoftAE/SoftAE.cpp
@@ -303,7 +303,7 @@ void CSoftAE::InternalOpenSink()
 
     /* perform basic sanity checks on the format returned by the sink */
     ASSERT(newFormat.m_channelLayout.Count() > 0);
-    ASSERT(newFormat.m_dataFormat           <= AE_FMT_FLOAT);
+    ASSERT(newFormat.m_dataFormat           <= AE_FMT_MAX);
     ASSERT(newFormat.m_frames                > 0);
     ASSERT(newFormat.m_frameSamples          > 0);
     ASSERT(newFormat.m_frameSize            == (CAEUtil::DataFormatToBits(newFormat.m_dataFormat) >> 3) * newFormat.m_channelLayout.Count());
