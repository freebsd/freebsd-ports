--- xmlcatalog.c.orig	Sun Jan 26 14:45:48 2003
+++ xmlcatalog.c	Wed Feb  5 19:18:49 2003
@@ -42,7 +42,7 @@
 #ifdef LIBXML_CATALOG_ENABLED
 
 #ifndef XML_SGML_DEFAULT_CATALOG
-#define XML_SGML_DEFAULT_CATALOG "/etc/sgml/catalog"
+#define XML_SGML_DEFAULT_CATALOG "%%LOCALBASE%%/share/sgml/catalog"
 #endif
 
 /************************************************************************
