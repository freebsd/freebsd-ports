--- src/input/r_wav.cpp.orig	2015-07-18 11:39:41 UTC
+++ src/input/r_wav.cpp
@@ -32,6 +32,10 @@
 #include "output/p_dts.h"
 #include "output/p_pcm.h"
 
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
 #define AC3ACM_READ_SIZE 100000
 
 wav_demuxer_c::wav_demuxer_c(wav_reader_c *reader,
