--- src/extras/xmlformatter.c.orig      Thu Apr  4 15:47:47 2002
+++ src/extras/xmlformatter.c   Thu Apr  4 15:48:50 2002
@@ -8,9 +8,9 @@

 #include <string.h>
 #include <gtk/gtk.h>
-#include <SAX.h>
-#include <parser.h>
-#include <parserInternals.h>
+#include <libxml/SAX.h>
+#include <libxml/parser.h>
+#include <libxml/parserInternals.h>

 #include <unistd.h>
