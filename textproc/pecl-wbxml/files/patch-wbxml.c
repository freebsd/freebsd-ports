--- wbxml.c.orig	2009-03-11 18:12:19.000000000 +0100
+++ wbxml.c	2009-03-11 18:12:27.000000000 +0100
@@ -27,6 +27,10 @@
 #include "ext/standard/info.h"
 #include "php_wbxml.h"
 
+#ifdef HAVE_EXPAT
+#include "expat.h"
+#endif
+
 #undef HAVE_LIBXML
 #include "wbxml.h"
 
