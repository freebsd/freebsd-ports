--- main/miscellaneous/dispatch.cc.orig	Wed Sep  1 21:50:51 2004
+++ main/miscellaneous/dispatch.cc	Wed Sep  1 21:51:19 2004
@@ -330,5 +330,5 @@
 
 
 #if defined(__GNUG__)
-template std::map<std::string,std::string>;
+template class std::map<std::string,std::string>;
 #endif
