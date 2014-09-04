--- php_xsl.h.orig	Sun Jan  1 13:50:17 2006
+++ php_xsl.h	Tue Jan 17 16:23:10 2006
@@ -43,7 +43,7 @@
 #include <libexslt/exsltconfig.h>
 #endif
 
-#include "../dom/xml_common.h"
+#include "ext/dom/xml_common.h"
 #include "xsl_fe.h"
 
 #include <libxslt/extensions.h>
