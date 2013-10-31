--- xc/programs/Xserver/vnc/XserverDesktop.h.orig	2008-10-16 08:16:20.000000000 -0700
+++ xc/programs/Xserver/vnc/XserverDesktop.h	2013-10-30 21:41:37.000000000 -0700
@@ -22,6 +22,7 @@
 #ifndef __XSERVERDESKTOP_H__
 #define __XSERVERDESKTOP_H__
 
+#include <sys/select.h>
 #include <rfb/SDesktop.h>
 #include <rfb/HTTPServer.h>
 #include <rfb/PixelBuffer.h>
