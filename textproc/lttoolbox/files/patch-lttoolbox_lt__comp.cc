--- lttoolbox/lt_comp.cc.orig	2025-07-26 16:26:30 UTC
+++ lttoolbox/lt_comp.cc
@@ -19,6 +19,7 @@
 #include <lttoolbox/lt_locale.h>
 #include <lttoolbox/cli.h>
 #include <lttoolbox/file_utils.h>
+#include <lttoolbox/xml_walk_util.h>
 
 #include <iostream>
 
@@ -104,6 +105,11 @@ int main(int argc, char *argv[])
   reader = xmlReaderForFile(infile.c_str(), NULL, 0);
   xmlGenericErrorFunc handler = (xmlGenericErrorFunc)errorFunc;
   initGenericErrorDefaultFunc(&handler);
+#if LIBXML_VERSION < 21200
+  initGenericErrorDefaultFunc(NULL);
+#else
+  xmlSetGenericErrorFunc(NULL, handler);  // match new signature if needed
+#endif
   if(reader != NULL)
   {
     int ret = xmlTextReaderRead(reader);
