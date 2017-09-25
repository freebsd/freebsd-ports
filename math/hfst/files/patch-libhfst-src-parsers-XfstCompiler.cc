--- libhfst/src/parsers/XfstCompiler.cc.orig	2014-07-04 18:26:59.000000000 +0400
+++ libhfst/src/parsers/XfstCompiler.cc	2014-07-04 18:27:09.000000000 +0400
@@ -18,6 +18,7 @@
 #   include <config.h>
 #endif
 
+#define _WITH_GETLINE
 #include <string>
 #include <map>
 #include <list>
