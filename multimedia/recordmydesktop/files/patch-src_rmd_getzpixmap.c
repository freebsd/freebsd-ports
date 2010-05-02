--- src/rmd_getzpixmap.c.orig	2008-12-14 02:04:10.000000000 +1000
+++ src/rmd_getzpixmap.c	2010-05-01 00:26:34.180209073 +1100
@@ -32,7 +32,7 @@
 
 #include <X11/Xlib.h>
 #include <X11/Xlibint.h>
-#include <X11/extensions/shmstr.h>
+#include <X11/extensions/shmproto.h>
 #include <X11/extensions/XShm.h>
 
 
