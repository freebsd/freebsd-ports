--- libs/uninstall.c.orig	Wed Jul 24 22:25:34 2002
+++ libs/uninstall.c	Thu Jan 16 01:50:53 2003
@@ -70,6 +70,8 @@
     int start, end;    
     char cl_filename[PATHLEN], cl_ext_filename[PATHLEN];
     xmlDocPtr cl_doc, cl_ext_doc;
+
+    setenv("XML_CATALOG_FILES", SK_XML_CATALOGS, 1);
     
     if (id_tab == NULL)
         return;
