--- lib/gtk-text-tag-addon.c.orig	Sun Mar 13 15:10:05 2005
+++ lib/gtk-text-tag-addon.c	Sun Mar 13 15:10:40 2005
@@ -37,6 +37,7 @@
  *
  */
 
+#include <unistd.h>
 #include "gtk-text-tag-addon.h"
 
 /*
