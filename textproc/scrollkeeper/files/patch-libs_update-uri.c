--- libs/update-url.c.orig	Thu Jan 16 01:41:36 2003
+++ libs/update-url.c	Thu Jan 16 01:41:40 2003
@@ -33,6 +33,7 @@
     xmlNodePtr node;
     xmlDocPtr omf_doc;
         
+    setenv("XML_CATALOG_FILES", SK_XML_CATALOGS, 1);
 
     /* Parse file and make sure it is well-formed */
     omf_doc = xmlParseFile(omf_name);
