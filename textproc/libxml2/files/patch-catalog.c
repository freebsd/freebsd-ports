--- catalog.c.orig	Mon Jun  3 15:28:28 2002
+++ catalog.c	Mon Jun  3 15:29:03 2002
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
