--- lib/rsa/rsa-sign.c.orig	2020-04-27 13:01:22.257655000 +0200
+++ lib/rsa/rsa-sign.c	2020-04-27 13:01:38.844321000 +0200
@@ -4,7 +4,7 @@
  */
 
 #include "mkimage.h"
-#include <malloc.h>
+#include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include <image.h>
