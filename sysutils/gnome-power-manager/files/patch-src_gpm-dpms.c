--- src/gpm-dpms.c.orig	2008-09-04 05:05:15.000000000 -0500
+++ src/gpm-dpms.c	2010-05-07 08:36:53.000000000 -0500
@@ -39,7 +39,7 @@
 #ifdef HAVE_DPMS_EXTENSION
 #include <X11/Xproto.h>
 #include <X11/extensions/dpms.h>
-#include <X11/extensions/dpmsstr.h>
+#include <X11/extensions/dpmsproto.h>
 #endif
 
 #include "gpm-conf.h"
