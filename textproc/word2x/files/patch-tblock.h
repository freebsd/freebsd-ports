--- tblock.h.dist	Thu Oct  8 03:12:09 1998
+++ tblock.h	Wed Mar 31 21:06:40 2004
@@ -4,6 +4,13 @@
 #ifndef __tblock_h__
 #define __tblock_h__
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
+
 class tblock
 {
 private:
