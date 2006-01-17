--- php_xsl.h.orig	Tue Jan 17 14:50:15 2006
+++ php_xsl.h	Tue Jan 17 14:50:53 2006
@@ -43,7 +43,11 @@
 #include <libexslt/exsltconfig.h>
 #endif
 
-#include "../dom/xml_common.h"
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
+#include "ext/dom/xml_common.h"
 #include "xsl_fe.h"
 
 #include <libxslt/extensions.h>
