--- src/gsad_base.c	2017-08-03 16:02:58.244183000 -0500
+++ src/gsad_base.c	2017-08-03 16:03:49.611595000 -0500
@@ -48,7 +48,7 @@
 #include <libxslt/xsltInternals.h> /* for xsltStylesheetPtr */
 #include <libxslt/transform.h> /* for xsltApplyStylesheet() */
 #include <libxslt/xsltutils.h> /* for xsltSaveResultToString() */
-#include <malloc.h>
+#include <stdlib.h>
 #else
 #include <string.h>
 #include <sys/wait.h>
@@ -339,7 +339,6 @@
 
   xsltFreeStylesheet (cur);
   xmlFreeDoc (res);
-  malloc_trim (0);
 
   return (char *) doc_txt_ptr;
 #else
