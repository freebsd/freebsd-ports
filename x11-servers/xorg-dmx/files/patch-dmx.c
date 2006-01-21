--- programs/Xserver/Xext/dmx.c.orig	Mon Jan 16 07:43:55 2006
+++ programs/Xserver/Xext/dmx.c	Mon Jan 16 07:44:29 2006
@@ -57,10 +57,10 @@
 #include "opaque.h"
 
 #include "dmxextension.h"
-#include <X11/extensions/dmxproto.h>
+#include "dmxproto.h"
 
 #define _DMX_SERVER_
-#include <X11/extensions/dmxext.h>
+#include "dmxext.h"
 
 #ifdef PANORAMIX
 #include "panoramiX.h"
