--- wbxml.c.orig	2009-01-29 19:13:57 UTC
+++ wbxml.c
@@ -27,8 +27,12 @@
 #include "ext/standard/info.h"
 #include "php_wbxml.h"
 
+#ifdef HAVE_EXPAT
+#include "expat.h"
+#endif
+
 #undef HAVE_LIBXML
-#include "wbxml.h"
+#include "wbxml/wbxml.h"
 
 /* {{{ wbxml_functions[]
  */
