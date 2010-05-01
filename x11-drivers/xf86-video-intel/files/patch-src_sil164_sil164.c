--- src/sil164/sil164.c.orig	2010-02-21 12:49:54.000000000 -0600
+++ src/sil164/sil164.c	2010-02-21 12:50:40.000000000 -0600
@@ -35,13 +35,11 @@
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
 #include "compiler.h"
 #include "miscstruct.h"
 #include "xf86i2c.h"
 #include "xf86Crtc.h"
-#define DPMS_SERVER
-#include <X11/extensions/dpms.h>
+#include <X11/extensions/dpmsproto.h>
 
 #include "../i2c_vid.h"
 #include "sil164.h"
