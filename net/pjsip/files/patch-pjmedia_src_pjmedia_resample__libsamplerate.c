--- pjmedia/src/pjmedia/resample_libsamplerate.c.orig	2011-05-05 06:14:19 UTC
+++ pjmedia/src/pjmedia/resample_libsamplerate.c
@@ -33,7 +33,7 @@
 
 #if PJMEDIA_RESAMPLE_IMP==PJMEDIA_RESAMPLE_LIBSAMPLERATE
 
-#include "../../third_party/libsamplerate/src/samplerate.h"
+#include <samplerate.h>
 
 #define THIS_FILE   "resample_libsamplerate.c"
 
