--- src/ch7xxx/ch7xxx.c.orig	2010-02-21 12:42:11.000000000 -0600
+++ src/ch7xxx/ch7xxx.c	2010-02-21 12:44:40.000000000 -0600
@@ -34,13 +34,11 @@
 #include <string.h>
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
 #include "ch7xxx.h"
