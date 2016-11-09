--- xbmc/cores/dvdplayer/DVDPlayerAudioResampler.cpp.orig	2015-05-11 07:54:22 UTC
+++ xbmc/cores/dvdplayer/DVDPlayerAudioResampler.cpp
@@ -74,7 +74,7 @@ void CDVDPlayerResampler::Add(DVDAudioFr
 
   //add samples to the resample input buffer
   int16_t* inputptr  = (int16_t*)audioframe.data;
-  float*   outputptr = m_converterdata.data_in;
+  float*   outputptr = (float*)m_converterdata.data_in;
 
   for (int i = 0; i < nrframes * m_nrchannels; i++)
     *outputptr++ = (float)*inputptr++ / scale;
