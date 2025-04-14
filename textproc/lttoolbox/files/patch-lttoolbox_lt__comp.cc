--- lttoolbox/lt_comp.cc.orig	2025-04-05 18:21:01 UTC
+++ lttoolbox/lt_comp.cc
@@ -19,6 +19,7 @@
 #include <lttoolbox/lt_locale.h>
 #include <lttoolbox/cli.h>
 #include <lttoolbox/file_utils.h>
+#include <lttoolbox/xml_walk_util.h>
 
 #include <iostream>
 
@@ -119,7 +120,11 @@ int main(int argc, char *argv[])
     std::cerr << "Error: Cannot not open file '" << infile << "'." << std::endl << std::endl;
     exit(EXIT_FAILURE);
   }
-  initGenericErrorDefaultFunc(NULL);
+#if LIBXML_VERSION < 21200
+    initGenericErrorDefaultFunc(NULL);
+#else
+    xmlSetGenericErrorFunc(NULL, handler);  // match new signature if needed
+#endif
 
 
   if(opc == "lr")
