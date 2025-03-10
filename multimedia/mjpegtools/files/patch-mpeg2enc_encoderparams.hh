Use class RateCtl instead of struct.
Class RateCtl is defined in ratectl.hh and used elsewhere in the code too.

--- mpeg2enc/encoderparams.hh.orig	2021-09-05 06:14:13 UTC
+++ mpeg2enc/encoderparams.hh
@@ -79,7 +79,7 @@ struct motion_data {
 };
 
 
-struct RateCtl;
+class RateCtl;
 class MPEG2EncOptions;
 
 class EncoderParams
