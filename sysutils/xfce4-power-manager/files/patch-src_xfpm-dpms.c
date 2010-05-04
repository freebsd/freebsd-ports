--- src/xfpm-dpms.c.orig	2010-05-04 10:58:28.000000000 +0200
+++ src/xfpm-dpms.c	2010-05-04 11:24:33.000000000 +0200
@@ -32,7 +32,7 @@
 
 #include <X11/Xproto.h>
 #include <X11/extensions/dpms.h>
-#include <X11/extensions/dpmsstr.h>
+#include <X11/extensions/dpmsproto.h>
 
 #include <libxfce4util/libxfce4util.h>
 
