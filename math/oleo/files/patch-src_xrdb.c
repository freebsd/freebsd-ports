--- src/xrdb.c.orig	Wed Jul 14 23:30:28 2004
+++ src/xrdb.c	Wed Jul 14 23:30:29 2004
@@ -57,7 +57,6 @@
 /* This should be included before the X include files; otherwise, we get
    warnings about redefining NULL under BSD 4.3.  */
 #include <sys/param.h>
-#define NeedFunctionPrototypes 0
 #include <X11/X.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
