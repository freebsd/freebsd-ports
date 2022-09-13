--- libs/libmythtv/io/mythavformatwriter.cpp.orig	2022-08-13 16:59:56 UTC
+++ libs/libmythtv/io/mythavformatwriter.cpp
@@ -270,7 +270,7 @@ int MythAVFormatWriter::WriteAudioFrame(unsigned char 
 #if (Q_BYTE_ORDER == Q_BIG_ENDIAN)
     auto buf16 = reinterpret_cast<uint16_t *>(Buffer);
     for (int i = 0; i < m_audioChannels * m_audioFrameSize; i++)
-        buf16[i] = qFromLittleEndian<uint16_t>(buf16[i]);
+        buf16[i] = qFromLittleEndian<quint16>(buf16[i]);
 #endif
 
     AVCodecContext *avctx   = m_codecMap.GetCodecContext(m_audioStream);
