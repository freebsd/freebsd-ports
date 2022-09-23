--- libs/libmyth/audio/audiooutpututil.cpp.orig	2022-08-13 16:59:56 UTC
+++ libs/libmyth/audio/audiooutpututil.cpp
@@ -212,9 +212,9 @@ char *AudioOutputUtil::GeneratePinkFrames(char *frames
                     static_cast<float>(0x03fffffff);
                 int32_t ires = res;
                 if (bits == 16)
-                    *samp16++ = qToLittleEndian<int16_t>(ires >> 16);
+                    *samp16++ = qToLittleEndian<qint16>(ires >> 16);
                 else
-                    *samp32++ = qToLittleEndian<int32_t>(ires);
+                    *samp32++ = qToLittleEndian<qint32>(ires);
             }
             else
             {
