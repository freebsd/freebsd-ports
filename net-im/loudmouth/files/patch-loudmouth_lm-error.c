--- loudmouth/lm-error.c.orig	2012-05-22 10:05:29.000000000 +0200
+++ loudmouth/lm-error.c	2012-05-22 10:05:41.000000000 +0200
@@ -19,7 +19,7 @@
  */
 
 #include <config.h>
-#include <glib/gerror.h>
+#include <glib.h>
 #include "lm-error.h"
 
 /**
