--- LocPixmap.c.orig	2019-07-03 20:23:26 UTC
+++ LocPixmap.c
@@ -30,6 +30,7 @@
 #include <X11/Xlib.h>
 #include <X11/Xresource.h>
 #include <X11/Xutil.h>
+#include <X11/Intrinsic.h>
 #include <X11/StringDefs.h>
 #include <sys/param.h>			/* get MAXPATHLEN if possible */
 #ifndef MAXPATHLEN
