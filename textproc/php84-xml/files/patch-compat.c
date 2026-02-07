--- compat.c.orig	2023-06-06 15:54:29 UTC
+++ compat.c
@@ -14,6 +14,10 @@
    +----------------------------------------------------------------------+
  */
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "php.h"
 #if defined(HAVE_LIBXML) && (defined(HAVE_XML) || defined(HAVE_XMLRPC)) && !defined(HAVE_LIBEXPAT)
 #include "expat_compat.h"
