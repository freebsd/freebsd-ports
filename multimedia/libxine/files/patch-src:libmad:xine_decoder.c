--- src/libmad/xine_decoder.c.orig	Sat Nov 30 11:56:16 2002
+++ src/libmad/xine_decoder.c	Sat Nov 30 12:00:04 2002
@@ -24,12 +24,11 @@
 
 #include <stdlib.h>
 #include <string.h>
+#include <mad.h>
 
 #include "xine_internal.h"
 #include "audio_out.h"
 #include "buffer.h"
-#include "frame.h"
-#include "synth.h"
 #include "xineutils.h"
 
 /*
