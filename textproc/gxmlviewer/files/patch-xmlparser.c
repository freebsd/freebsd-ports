--- src/xmlparser.c.orig        Thu Apr  4 17:05:35 2002
+++ src/xmlparser.c     Thu Apr  4 17:08:09 2002
@@ -8,15 +8,9 @@

 #include <string.h>
 #include <gtk/gtk.h>
-#ifndef WIN32
-#include <SAX.h>
-#include <parser.h>
-#include <parserInternals.h>
-#else
 #include <libxml/SAX.h>
 #include <libxml/parser.h>
 #include <libxml/parserInternals.h>
-#endif
 #include "xmlparser.h"
 #include "support.h"
