--- src/battfink-dpms.c.orig	2010-05-03 23:55:33.000000000 +0200
+++ src/battfink-dpms.c	2010-05-03 23:56:11.000000000 +0200
@@ -37,7 +37,6 @@
 #include <X11/Xlib.h>
 #include <X11/Xproto.h>
 #include <X11/extensions/dpms.h>
-#include <X11/extensions/dpmsstr.h>
 
 extern Bool   DPMSQueryExtension  (Display *dpy, int *event_ret, int *err_ret);
 extern Bool   DPMSCapable         (Display *dpy);
