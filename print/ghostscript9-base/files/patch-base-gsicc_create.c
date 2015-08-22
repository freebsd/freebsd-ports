--- base/gsicc_create.c.orig	2011-08-05 20:12:20.000000000 +0900
+++ base/gsicc_create.c	2011-12-06 15:23:14.000000000 +0900
@@ -113,6 +113,7 @@
 
    */
 
+#include <sys/types.h>
 #include "icc34.h"   /* Note this header is needed even if lcms is not
                             compiled as default CMS */
 #include "string_.h"
