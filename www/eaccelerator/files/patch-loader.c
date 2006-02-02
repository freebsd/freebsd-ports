--- loader.c.orig	Wed Aug  3 20:54:32 2005
+++ loader.c	Thu Feb  2 09:40:00 2006
@@ -39,6 +39,10 @@
 #include "php.h"
 #include "ea_restore.h"
 #include <math.h>
+
+#ifdef HAVE_EACCELERATOR_STANDALONE_LOADER
+zend_extension* ZendOptimizer = NULL;
+#endif
 
 typedef struct loader_data {
   long  version;
