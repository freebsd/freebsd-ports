--- catalog.c.orig	Wed Jan 15 17:35:09 2003
+++ catalog.c	Wed Jan 15 17:36:03 2003
@@ -56,10 +56,10 @@
 #define XML_URN_PUBID "urn:publicid:"
 #define XML_CATAL_BREAK ((xmlChar *) -1)
 #ifndef XML_XML_DEFAULT_CATALOG
-#define XML_XML_DEFAULT_CATALOG "file:///etc/xml/catalog"
+#define XML_XML_DEFAULT_CATALOG "file://%%LOCALBASE%%/share/xml/catalog"
 #endif
 #ifndef XML_SGML_DEFAULT_CATALOG
-#define XML_SGML_DEFAULT_CATALOG "file:///etc/sgml/catalog"
+#define XML_SGML_DEFAULT_CATALOG "file://%%LOCALBASE%%/share/sgml/catalog"
 #endif
 
 static int xmlExpandCatalog(xmlCatalogPtr catal, const char *filename);
