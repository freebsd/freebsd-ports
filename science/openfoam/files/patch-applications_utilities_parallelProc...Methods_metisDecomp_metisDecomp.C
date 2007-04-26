--- ./applications/utilities/parallelProcessing/decompositionMethods/metisDecomp/metisDecomp.C.orig	Wed Mar 28 17:10:00 2007
+++ ./applications/utilities/parallelProcessing/decompositionMethods/metisDecomp/metisDecomp.C	Fri Apr 20 07:39:47 2007
@@ -33,7 +33,7 @@
 
 extern "C"
 {
-#   include "metis.h"
+#   include <metis/metis.h>
 }
 
 
