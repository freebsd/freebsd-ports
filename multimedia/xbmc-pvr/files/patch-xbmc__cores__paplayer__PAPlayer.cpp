--- xbmc/cores/paplayer/PAPlayer.cpp.orig
+++ xbmc/cores/paplayer/PAPlayer.cpp
@@ -341,7 +341,8 @@
 
   if(silence > 0 && m_bufferPos[stream] > 0)
   {
-    CLog::Log(LOGDEBUG, "PAPlayer: Drain - adding %d bytes of silence, real pcmdata size: %d, chunk size: %d", silence, m_bufferPos[stream], m_pAudioDecoder[stream]->GetChunkLen());
+    CLog::Log(LOGDEBUG, "PAPlayer: Drain - adding %d bytes of silence, real pcmdata size: %d, chunk size: %d",
+      (int)silence, m_bufferPos[stream], m_pAudioDecoder[stream]->GetChunkLen());
     memset(m_pcmBuffer[stream] + m_bufferPos[stream], 0, silence);
     m_bufferPos[stream] += silence;
   }
