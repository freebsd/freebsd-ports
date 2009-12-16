--- ./src/xmlpull/XmlUtils.cpp.orig	2009-12-16 02:36:41.855644800 +0000
+++ ./src/xmlpull/XmlUtils.cpp	2009-12-16 02:37:03.225260481 +0000
@@ -212,7 +212,7 @@
     // - use-case with a single '/' added (I am not sure this is conform to spec)
 // #ifdef _WIN32
 #if     !defined(_WIN32)
-    unsigned int p;
+    size_t p;
     if ((p=uri.find("file:///"))!=std::string::npos)
       {
 	uri = uri.substr(p+7, uri.length()-p-7);
