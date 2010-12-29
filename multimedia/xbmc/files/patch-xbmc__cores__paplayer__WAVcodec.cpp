--- ./xbmc/cores/paplayer/WAVcodec.cpp.orig	2010-06-03 06:23:58.000000000 +0200
+++ ./xbmc/cores/paplayer/WAVcodec.cpp	2010-12-01 12:17:34.221698375 +0100
@@ -137,7 +137,7 @@
             return false;
           }
           m_ChannelMask = Endian_SwapLE32(wfx.dwChannelMask);
-          CLog::Log(LOGINFO, "WAVCodec::Init - WAVE_FORMAT_EXTENSIBLE detected, channel mask: %d", m_ChannelMask);
+          CLog::Log(LOGINFO, "WAVCodec::Init - WAVE_FORMAT_EXTENSIBLE detected, channel mask: %d", (int)m_ChannelMask);
 
           wfx.SubFormat.Data1 = Endian_SwapLE32(wfx.SubFormat.Data1);
           wfx.SubFormat.Data2 = Endian_SwapLE16(wfx.SubFormat.Data2);
