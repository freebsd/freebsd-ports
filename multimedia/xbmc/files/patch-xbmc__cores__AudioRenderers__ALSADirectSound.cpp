--- ./xbmc/cores/AudioRenderers/ALSADirectSound.cpp.orig	2010-10-25 16:43:36.000000000 +0200
+++ ./xbmc/cores/AudioRenderers/ALSADirectSound.cpp	2010-12-01 12:17:34.212621188 +0100
@@ -439,7 +439,7 @@
 {
   if (!m_bIsAllocated) return 0;
 
-  int nSpace = snd_pcm_avail_update(m_pPlayHandle);
+  snd_pcm_sframes_t nSpace = snd_pcm_avail_update(m_pPlayHandle);
   if (nSpace == 0)
   {
     snd_pcm_state_t state = snd_pcm_state(m_pPlayHandle);
@@ -451,7 +451,8 @@
   }
   if (nSpace < 0)
   {
-     CLog::Log(LOGWARNING,"CALSADirectSound::GetSpace - get space failed. err: %d (%s)", nSpace, snd_strerror(nSpace));
+     CLog::Log(LOGWARNING,"CALSADirectSound::GetSpace - get space failed. err: %ld (%s)",
+	 	(long)nSpace, snd_strerror(nSpace));
      nSpace = 0;
      Flush();
   }
