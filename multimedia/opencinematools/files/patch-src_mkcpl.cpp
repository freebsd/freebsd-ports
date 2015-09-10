--- src/mkcpl.cpp.orig
+++ src/mkcpl.cpp
@@ -589,7 +589,7 @@
 	              PCMReader.FillWriterInfo(WInfo);
 
                 AAssets.push_back(Asset());
-                sprintf(buff, "%u %u", ADesc.SampleRate.Numerator, ADesc.SampleRate.Denominator);
+                sprintf(buff, "%u %u", ADesc.AudioSamplingRate.Numerator, ADesc.AudioSamplingRate.Denominator);
                 AAssets.back().EditRate = buff;
 
                 AAssets.back().IntrinsicDuration = ADesc.ContainerDuration;
