--- rbcrack.c.orig	Wed Sep 18 16:45:57 2002
+++ rbcrack.c	Fri Sep 20 04:46:38 2002
@@ -5,7 +5,11 @@
  */
 
 #include "ruby.h"
-#include "crack.h"
+#ifdef HAVE_PACKER_H
+#include <packer.h>
+#else
+#include <crack.h>
+#endif
 #include "rbcrack.h"
 
 #define CRACK_VERSION "0.2.0"
