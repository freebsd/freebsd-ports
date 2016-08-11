--- base/gsicc_create.c.orig	2015-03-30 08:21:24 UTC
+++ base/gsicc_create.c
@@ -116,6 +116,7 @@ Note: All profile data must be encoded a
 
    */
 
+#include <sys/types.h>
 #include "icc34.h"   /* Note this header is needed even if lcms is not
                             compiled as default CMS */
 #include "string_.h"
