--- xbmc/cores/dvdplayer/DVDAudio.cpp.orig
+++ xbmc/cores/dvdplayer/DVDAudio.cpp
@@ -237,14 +237,14 @@ void CDVDAudio::Finish()
 
   if(silence > 0 && m_iBufferSize > 0)
   {
-    CLog::Log(LOGDEBUG, "CDVDAudio::Drain - adding %d bytes of silence, buffer size: %d, chunk size: %d", silence, m_iBufferSize, m_dwPacketSize);
+    CLog::Log(LOGDEBUG, "CDVDAudio::Drain - adding %d bytes of silence, buffer size: %d, chunk size: %d", (int)silence, (int)m_iBufferSize, (int)m_dwPacketSize);
     m_pBuffer = (BYTE*)realloc(m_pBuffer, m_iBufferSize + silence);
     memset(m_pBuffer+m_iBufferSize, 0, silence);
     m_iBufferSize += silence;
   }
 
   if(AddPacketsRenderer(m_pBuffer, m_iBufferSize, lock) != m_iBufferSize)
-    CLog::Log(LOGERROR, "CDVDAudio::Drain - failed to play the final %d bytes", m_iBufferSize);
+    CLog::Log(LOGERROR, "CDVDAudio::Drain - failed to play the final %d bytes", (int)m_iBufferSize);
 
   m_iBufferSize = 0;
 }
