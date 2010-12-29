--- ./xbmc/cores/paplayer/PAPlayer.cpp.orig	2010-09-30 12:17:21.000000000 +0200
+++ ./xbmc/cores/paplayer/PAPlayer.cpp	2010-12-01 12:17:34.224719076 +0100
@@ -341,7 +341,8 @@
 
   if(silence > 0 && m_bufferPos[stream] > 0)
   {
-    CLog::Log(LOGDEBUG, "PAPlayer: Drain - adding %d bytes of silence, real pcmdata size: %d, chunk size: %d", silence, m_bufferPos[stream], m_pAudioDecoder[stream]->GetChunkLen());
+    CLog::Log(LOGDEBUG, "PAPlayer: Drain - adding %d bytes of silence, real pcmdata size: %d, chunk size: %d",
+      (int)silence, m_bufferPos[stream], m_pAudioDecoder[stream]->GetChunkLen());
     memset(m_pcmBuffer[stream] + m_bufferPos[stream], 0, silence);
     m_bufferPos[stream] += silence;
   }
@@ -896,7 +897,7 @@
   {
     DWORD time = CTimeUtils::GetTimeMS();
     m_timeOffset = m_decoder[m_currentDecoder].Seek(m_SeekTime);
-    CLog::Log(LOGDEBUG, "Seek to time %f took %i ms", 0.001f * m_SeekTime, CTimeUtils::GetTimeMS() - time);
+    CLog::Log(LOGDEBUG, "Seek to time %f took %i ms", 0.001f * m_SeekTime, (int)(CTimeUtils::GetTimeMS() - time));
     FlushStreams();
     m_SeekTime = -1;
   }
