--- src/plugin_dialog.cpp.orig	Mon Mar 27 17:59:06 2000
+++ src/plugin_dialog.cpp	Tue Sep 19 21:47:13 2000
@@ -1,5 +1,6 @@
 #include "gtk-gui.h"
 
+#include <unistd.h>
 #include <sys/time.h>
 #include <stdio.h>
 #include <sys/types.h>
