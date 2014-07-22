Use class RateCtl instead of struct.
Class RateCtl is defined in ratectl.hh and used elsewhere in the code too.

--- ./mpeg2enc/encoderparams.hh.orig	2014-07-21 16:50:46.000000000 +0200
+++ ./mpeg2enc/encoderparams.hh	2014-07-21 16:50:56.000000000 +0200
@@ -79,7 +79,7 @@
 };
 
 
-struct RateCtl;
+class RateCtl;
 class MPEG2EncOptions;
 
 class EncoderParams
