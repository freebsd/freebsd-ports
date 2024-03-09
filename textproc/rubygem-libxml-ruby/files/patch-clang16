--- ext/libxml/ruby_xml_error.c.orig	2024-02-29 10:00:08.939749000 +0000
+++ ext/libxml/ruby_xml_error.c	2024-02-29 10:03:09.239975000 +0000
@@ -97,7 +97,7 @@
 }
 
 /* Hook that receives xml error message */
-static void structuredErrorFunc(void *userData, const xmlError *xerror)
+static void structuredErrorFunc(void *userData, xmlError *xerror)
 {
   VALUE error = rxml_error_wrap(xerror);
 
