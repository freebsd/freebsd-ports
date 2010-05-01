--- src/ivch/ivch.c.orig	2010-02-21 12:47:05.000000000 -0600
+++ src/ivch/ivch.c	2010-02-21 12:48:09.000000000 -0600
@@ -31,13 +31,11 @@
 
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
 #include <unistd.h>
 
 #include "../i2c_vid.h"
