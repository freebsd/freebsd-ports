--- src/liba52/xine_decoder.c.orig	Tue Feb 18 07:15:22 2003
+++ src/liba52/xine_decoder.c	Tue Mar 25 00:39:52 2003
@@ -37,8 +37,8 @@
 
 #include "xine_internal.h"
 #include "audio_out.h"
-#include "a52.h"
-#include "a52_internal.h"
+#include <a52dec/a52.h>
+#include <a52dec/a52_internal.h>
 #include "buffer.h"
 #include "xineutils.h"
 
