--- base/gsicc_create.c.orig	2011-05-23 13:33:34.000000000 +0900
+++ base/gsicc_create.c	2011-05-23 13:33:52.000000000 +0900
@@ -116,6 +116,7 @@
    
    */
 
+#include <sys/types.h>
 #include "icc34.h"   /* Note this header is needed even if lcms is not 
                             compiled as default CMS */
 #include "string_.h"
@@ -2350,4 +2351,4 @@
     icHeader  *header = &(iccprofile.header);
 
     setheader_common(header);
-}
\ No newline at end of file
+}
