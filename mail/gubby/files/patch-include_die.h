--- include/die.h.orig	2004-12-18 04:29:19 UTC
+++ include/die.h
@@ -1,6 +1,7 @@
 // Gubby
 // csl@sublevel3.org
 
+#include <cstdlib>
 #include <string>
 
 void die(const std::string& s);
