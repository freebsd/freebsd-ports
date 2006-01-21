--- programs/Xserver/hw/dmx/dmxextension.c.orig	Mon Jan 16 07:48:33 2006
+++ programs/Xserver/hw/dmx/dmxextension.c	Mon Jan 16 07:51:33 2006
@@ -62,7 +62,7 @@
 
 #include "windowstr.h"
 #include "inputstr.h"                 /* For DeviceIntRec */
-#include <X11/extensions/dmxproto.h>  /* For DMX_BAD_* */
+#include "dmxproto.h"                 /* For DMX_BAD_* */
 #include "cursorstr.h"
 
 /* The default font is declared in dix/globals.c, but is not included in
