Note the second chunk in this patch can be removed on the next release.  It
was added to crrect GNOME Bug#96963 which broke the 
SGML_CATALOG_FILES variable.

--- catalog.c.orig	Sat Oct  5 04:35:13 2002
+++ catalog.c	Thu Nov 14 01:41:06 2002
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
@@ -2938,7 +2938,7 @@
 	while (IS_BLANK(*cur)) cur++;
 	if (*cur != 0) {
 	    paths = cur;
-	    while ((*cur != 0) && (!IS_BLANK(*cur)))
+	    while ((*cur != 0) && (*cur != ':') && (!IS_BLANK(*cur)))
 		cur++;
 	    path = xmlStrndup((const xmlChar *)paths, cur - paths);
 	    if (path != NULL) {
@@ -2946,6 +2946,8 @@
 		xmlFree(path);
 	    }
 	}
+	while(*cur == ':')
+	  cur++;
     }
 }
 
