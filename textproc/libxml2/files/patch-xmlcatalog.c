--- xmlcatalog.c.orig	Mon Jun  3 15:30:00 2002
+++ xmlcatalog.c	Mon Jun  3 15:30:17 2002
@@ -41,7 +41,7 @@
 
 #ifdef LIBXML_CATALOG_ENABLED
 
-#define XML_SGML_DEFAULT_CATALOG "/etc/sgml/catalog"
+#define XML_SGML_DEFAULT_CATALOG "%%LOCALBASE%%/share/sgml/catalog"
 
 /************************************************************************
  * 									*
