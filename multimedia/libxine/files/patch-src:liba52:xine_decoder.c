--- src/liba52/xine_decoder.c.orig	Mon Nov 25 06:08:51 2002
+++ src/liba52/xine_decoder.c	Sat Nov 30 11:38:41 2002
@@ -37,8 +37,8 @@
 
 #include "xine_internal.h"
 #include "audio_out.h"
-#include "a52.h"
-#include "a52_internal.h"
+#include <a52dec/a52.h>
+#include <a52dec/a52_internal.h>
 #include "buffer.h"
 #include "xineutils.h"
 
