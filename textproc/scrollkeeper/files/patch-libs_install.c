--- libs/install.c.orig	Wed Jan 15 23:27:11 2003
+++ libs/install.c	Wed Jan 15 23:26:31 2003
@@ -165,6 +165,12 @@
     char *toc_stylesheet_name, *index_name, *index_stylesheet_name, *uid;
 
     /*
+     * Set up a custom catalog path.
+     */
+
+    setenv("XML_CATALOG_FILES", SK_XML_CATALOGS, 1);
+
+    /*
      * Read in OMF file
      */
     omf_doc = xmlParseFile(omf_name);
