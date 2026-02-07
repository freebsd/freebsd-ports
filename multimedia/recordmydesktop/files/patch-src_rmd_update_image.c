--- src/rmd_update_image.c.orig	2008-12-14 02:20:49.000000000 +1000
+++ src/rmd_update_image.c	2010-05-01 00:26:55.314353706 +1100
@@ -32,7 +32,7 @@
 #include "rmd_types.h"
 
 #include <X11/Xlibint.h>
-#include <X11/extensions/shmstr.h>
+#include <X11/extensions/shmproto.h>
 #include <X11/extensions/XShm.h>
 
 
