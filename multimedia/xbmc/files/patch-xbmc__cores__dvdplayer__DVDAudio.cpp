--- ./xbmc/cores/dvdplayer/DVDAudio.cpp.orig	2010-05-05 11:33:40.000000000 +0200
+++ ./xbmc/cores/dvdplayer/DVDAudio.cpp	2010-12-01 12:17:34.200531401 +0100
@@ -235,13 +235,14 @@
 
   if(silence > 0 && m_iBufferSize > 0)
   {
-    CLog::Log(LOGDEBUG, "CDVDAudio::Drain - adding %d bytes of silence, buffer size: %d, chunk size: %d", silence, m_iBufferSize, m_dwPacketSize);
+    CLog::Log(LOGDEBUG, "CDVDAudio::Drain - adding %d bytes of silence, buffer size: %d, chunk size: %d",
+      (int)silence, (int)m_iBufferSize, (int)m_dwPacketSize);
     memset(m_pBuffer+m_iBufferSize, 0, silence);
     m_iBufferSize += silence;
   }
 
   if(AddPacketsRenderer(m_pBuffer, m_iBufferSize, lock) != m_iBufferSize)
-    CLog::Log(LOGERROR, "CDVDAudio::Drain - failed to play the final %d bytes", m_iBufferSize);
+    CLog::Log(LOGERROR, "CDVDAudio::Drain - failed to play the final %d bytes", (int)m_iBufferSize);
 
   m_iBufferSize = 0;
 }
