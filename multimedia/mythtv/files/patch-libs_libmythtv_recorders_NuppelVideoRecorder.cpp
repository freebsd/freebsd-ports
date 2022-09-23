--- libs/libmythtv/recorders/NuppelVideoRecorder.cpp.orig	2022-08-13 16:59:56 UTC
+++ libs/libmythtv/recorders/NuppelVideoRecorder.cpp
@@ -16,6 +16,7 @@
 #include <cmath>
 
 #include <QStringList>
+#include <QtEndian>
 
 #include <iostream>
 
@@ -2558,7 +2559,7 @@ void NuppelVideoRecorder::WriteAudio(unsigned char *bu
 #if (Q_BYTE_ORDER == Q_BIG_ENDIAN)
         auto buf16 = reinterpret_cast<uint16_t *>(buf);
         for (int i = 0; i < m_audioChannels * sample_cnt; i++)
-            buf16[i] = qToLittleEndian<uint16_t>(buf16[i]);
+            buf16[i] = qToLittleEndian<quint16>(buf16[i]);
 #endif
         if (m_audioChannels == 2)
         {
