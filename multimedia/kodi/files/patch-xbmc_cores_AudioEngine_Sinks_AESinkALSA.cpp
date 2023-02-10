--- xbmc/cores/AudioEngine/Sinks/AESinkALSA.cpp.orig	2022-05-22 10:57:33 UTC
+++ xbmc/cores/AudioEngine/Sinks/AESinkALSA.cpp
@@ -949,13 +949,6 @@ void CAESinkALSA::HandleError(const char* name, int er
   {
     case -EPIPE:
       CLog::Log(LOGERROR, "CAESinkALSA::HandleError({}) - underrun", name);
-      if ((err = snd_pcm_prepare(m_pcm)) < 0)
-        CLog::Log(LOGERROR, "CAESinkALSA::HandleError({}) - snd_pcm_prepare returned {} ({})", name,
-                  err, snd_strerror(err));
-      break;
-
-    case -ESTRPIPE:
-      CLog::Log(LOGINFO, "CAESinkALSA::HandleError({}) - Resuming after suspend", name);
 
       /* try to resume the stream */
       while((err = snd_pcm_resume(m_pcm)) == -EAGAIN)
