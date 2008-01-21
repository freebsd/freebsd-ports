--- Utils.cxx.orig	2008-01-15 16:01:46.000000000 +0000
+++ Utils.cxx	2008-01-15 16:02:07.000000000 +0000
@@ -10,7 +10,8 @@
 #include "Utils.h"
 
 #include <fstream>
-
+#include <assert.h>
+
 void wtrim(string& str) {
  const char* sp_chars = " \t\r\n";
  unsigned int fst_notsp = str.find_first_not_of(sp_chars);
