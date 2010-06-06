--- src/sound.cpp.orig	2010-06-06 16:28:57.000000000 +0200
+++ src/sound.cpp	2010-06-06 16:29:34.000000000 +0200
@@ -173,6 +173,7 @@ void SoundLibAo::play(VyEvent evt)/*{{{*
 	{
 		ao_sample_format frmt;
 		
+		memset(&frmt, 0, sizeof(frmt));
 		frmt.bits = sizeof(short) << 3;
 		frmt.channels = sfinf[evt].channels;
 		frmt.rate = sfinf[evt].samplerate;
