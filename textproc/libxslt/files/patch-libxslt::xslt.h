
$FreeBSD$

--- libxslt/xslt.h	2001/12/06 12:04:42	1.1
+++ libxslt/xslt.h	2001/12/06 12:07:32
@@ -11,6 +11,12 @@
 
 #include <libxml/tree.h>
 
+#if defined(WIN32) && defined(_MSC_VER)
+#include <libxslt/xsltwin32config.h>
+#else
+#include <libxslt/xsltconfig.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
