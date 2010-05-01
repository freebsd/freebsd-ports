--- src/ch7017/ch7017.c.orig	2009-04-08 18:59:47.000000000 -0500
+++ src/ch7017/ch7017.c	2010-02-21 12:40:12.000000000 -0600
@@ -34,13 +34,11 @@
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86Resources.h"
 #include "compiler.h"
 #include "miscstruct.h"
 #include "xf86i2c.h"
 #include "xf86Crtc.h"
-#define DPMS_SERVER
-#include <X11/extensions/dpms.h>
+#include <X11/extensions/dpmsconst.h>
 
 #include "../i2c_vid.h"
 #include "ch7017_reg.h"
