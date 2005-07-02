--- human.c.orig	Sat Jul  2 23:12:17 2005
+++ human.c	Sat Jul  2 23:12:31 2005
@@ -19,6 +19,7 @@
    --si, output block size selection, and large file support
    added by eggert@twinsun.com.  */
 
+#include "dcfldd.h"
 #if HAVE_CONFIG_H
 # include <config.h>
 #endif
