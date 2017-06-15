--- compat.c.orig	Tue Jul 20 10:55:02 2004
+++ compat.c	Tue Jul 20 10:55:55 2004
@@ -16,6 +16,10 @@
    +----------------------------------------------------------------------+
  */
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "php.h"
 #if defined(HAVE_LIBXML) && defined(HAVE_XML) && !defined(HAVE_LIBEXPAT)
 #include "expat_compat.h"
