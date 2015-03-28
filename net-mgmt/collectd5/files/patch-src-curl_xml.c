--- src/curl_xml.c.orig	2015-03-28 23:25:34.546602000 +0300
+++ src/curl_xml.c	2015-03-28 23:25:51.513304000 +0300
@@ -385,7 +385,7 @@ static int cx_handle_instance_xpath (xml
   /* If the base xpath returns more than one block, the result is assumed to be
    * a table. The `Instance' option is not optional in this case. Check for the
    * condition and inform the user. */
-  if (is_table)
+  if (is_table && (vl->type_instance == NULL))
   {
     WARNING ("curl_xml plugin: "
         "Base-XPath %s is a table (more than one result was returned), "
