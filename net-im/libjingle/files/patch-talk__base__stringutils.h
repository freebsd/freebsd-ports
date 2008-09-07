--- talk/base/stringutils.h.orig	2008-09-06 23:10:21.000000000 -0300
+++ talk/base/stringutils.h	2008-09-06 23:13:17.000000000 -0300
@@ -269,7 +269,7 @@
 template<>
 struct Traits<char> {
   typedef std::string string;
-  inline static const char* Traits<char>::empty_str() { return ""; }
+  inline static const char* empty_str() { return ""; } 
 };
 
 ///////////////////////////////////////////////////////////////////////////////
