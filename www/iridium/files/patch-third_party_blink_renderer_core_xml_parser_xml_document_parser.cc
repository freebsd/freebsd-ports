--- third_party/blink/renderer/core/xml/parser/xml_document_parser.cc.orig	2018-07-20 01:07:52.189302000 +0200
+++ third_party/blink/renderer/core/xml/parser/xml_document_parser.cc	2018-07-20 01:10:37.425716000 +0200
@@ -28,6 +28,10 @@
 
 #include <libxml/parser.h>
 #include <libxml/parserInternals.h>
+#include <libxml/xmlversion.h>
+#if defined(LIBXML_CATALOG_ENABLED)
+#include <libxml/catalog.h>
+#endif
 #include <libxslt/xslt.h>
 
 #include <memory>
@@ -646,6 +650,9 @@
   if (did_init)
     return;
 
+#if defined(LIBXML_CATALOG_ENABLED)
+  xmlCatalogSetDefaults(XML_CATA_ALLOW_NONE);
+#endif
   xmlInitParser();
   xmlRegisterInputCallbacks(MatchFunc, OpenFunc, ReadFunc, CloseFunc);
   xmlRegisterOutputCallbacks(MatchFunc, OpenFunc, WriteFunc, CloseFunc);
