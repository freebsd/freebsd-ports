--- draw.c.orig	Fri Apr 11 12:47:47 2003
+++ draw.c	Fri Apr 11 12:47:54 2003
@@ -24,7 +24,7 @@
 
 #include "dockapp.h"
 #include "draw.h"
-#include "mem_linux.h"
+#include "mem_freebsd.h"
 #include "options.h"
 
 void draw_window()
