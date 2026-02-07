--- src/xrdb.c.orig	2000-08-10 21:02:51 UTC
+++ src/xrdb.c
@@ -57,7 +57,6 @@
 /* This should be included before the X include files; otherwise, we get
    warnings about redefining NULL under BSD 4.3.  */
 #include <sys/param.h>
-#define NeedFunctionPrototypes 0
 #include <X11/X.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
