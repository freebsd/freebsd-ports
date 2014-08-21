--- xbmc/cdrip/EncoderFFmpeg.cpp.orig 2013-02-06 19:11:19.000000000 +0100
+++ xbmc/cdrip/EncoderFFmpeg.cpp 2013-02-06 19:11:45.000000000 +0100
@@ -77,7 +77,13 @@
   }

   m_Format     = m_dllAvFormat.avformat_alloc_context();
+#if LIBAVFORMAT_VERSION_INT >= AV_VERSION_INT(53,1,0)
   m_Format->pb = m_dllAvFormat.avio_alloc_context(m_BCBuffer, sizeof(m_BCBuffer), AVIO_FLAG_READ, this,  NULL, MuxerReadPacket, NULL);
+#elif LIBAVFORMAT_VERSION_INT >= AV_VERSION_INT(53,0,0)
+  m_Format->pb = m_dllAvFormat.avio_alloc_context(m_BCBuffer, sizeof(m_BCBuffer), AVIO_RDONLY, this,  NULL, MuxerReadPacket, NULL);
+#else
+  m_Format->pb = m_dllAvFormat.avio_alloc_context(m_BCBuffer, sizeof(m_BCBuffer), URL_RDONLY, this,  NULL, MuxerReadPacket, NULL);
+#endif
   if (!m_Format->pb)
   {
     m_dllAvUtil.av_freep(&m_Format);
