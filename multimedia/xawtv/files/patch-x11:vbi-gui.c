--- x11/vbi-gui.c.orig	2008-02-17 11:15:44.000000000 +0100
+++ x11/vbi-gui.c	2008-02-17 11:16:07.000000000 +0100
@@ -44,6 +44,7 @@
 #include "vbi-x11.h"
 #include "vbi-gui.h"
 
+#include "grab-ng.h"
 #include "channel.h"
 
 static int tt_debug = 1;
