--- src/backend/common/t1lib_T1FontManager.cc.orig	2013-10-04 14:47:31.000000000 +0200
+++ src/backend/common/t1lib_T1FontManager.cc	2013-10-04 14:48:31.000000000 +0200
@@ -25,6 +25,8 @@
 #include "t1lib_T1Font.hh"
 #include "t1lib_T1FontManager.hh"
 
+#include <cstdlib>
+
 bool t1lib_T1FontManager::firstTime = true;
 
 // #include <iostream>
