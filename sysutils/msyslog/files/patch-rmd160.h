--- src/peo/rmd160.h.orig	Sun May 13 00:40:04 2001
+++ src/peo/rmd160.h	Sun May 13 00:40:23 2001
@@ -20,7 +20,7 @@
 #ifndef  _RMD160_H	/* make sure this file is read only once */
 #define  _RMD160_H
 
-#include "typedefs.h"
+#include <sys/types.h>
 
 /********************************************************************/
 
