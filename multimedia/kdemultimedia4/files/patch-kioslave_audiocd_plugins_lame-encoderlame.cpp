--- kioslave/audiocd/plugins/lame/encoderlame.cpp.orig	2007-10-25 14:58:32.000000000 +0200
+++ kioslave/audiocd/plugins/lame/encoderlame.cpp	2007-10-25 14:58:42.000000000 +0200
@@ -17,7 +17,7 @@
 */
 
 #include <config.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include "encoderlame.h"
 #include "encoderlameconfig.h"
 #include "audiocd_lame_encoder.h"
@@ -221,7 +221,7 @@
 	// -x bitswap
 	// -r raw/pcm
 	// -s 44.1 (because it is raw you have to specify this)
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if BYTE_ORDER == LITTLE_ENDIAN
 	*(d->currentEncodeProcess)	<< "lame" << "--verbose" << "-x" << "-r" << "-s" << "44.1";
 #else
 	*(d->currentEncodeProcess)      << "lame" << "--verbose" << "-r" << "-s" << "44.1";
