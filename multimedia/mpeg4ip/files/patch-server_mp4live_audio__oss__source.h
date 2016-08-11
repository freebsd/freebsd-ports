--- server/mp4live/audio_oss_source.h.orig	2006-05-15 17:52:52 UTC
+++ server/mp4live/audio_oss_source.h
@@ -104,7 +104,7 @@ class CAudioCapabilities : public CCapab
 	return rate;
       }
       int32_t calc;
-      calc = abs(m_samplingRates[ix] - rate);
+      calc = abs((int)(m_samplingRates[ix] - rate));
       if (calc < diff) {
 	diff = calc;
 	ret_rate = m_samplingRates[ix];
