--- libxml++/parsers/parser.cc.orig	Sat Feb  7 02:11:35 2004
+++ libxml++/parsers/parser.cc	Fri Feb 20 00:02:22 2004
@@ -9,6 +9,7 @@
 #include <libxml/parser.h>
 
 #include <cstdarg> //For va_list.
+#include <memory>
 
 namespace xmlpp {
 
