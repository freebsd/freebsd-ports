--- modules/codec/flac.c.orig	2013-01-25 13:30:14.000000000 +0100
+++ modules/codec/flac.c	2013-06-10 14:39:04.000000000 +0200
@@ -38,8 +38,8 @@
 #include <vlc_codec.h>
 #include <vlc_aout.h>
 
-#include <stream_decoder.h>
-#include <stream_encoder.h>
+#include <FLAC/stream_decoder.h>
+#include <FLAC/stream_encoder.h>
 
 #include <vlc_block_helper.h>
 #include <vlc_bits.h>
