--- src/gdlgstream.hpp.orig	2017-05-19 17:32:58 UTC
+++ src/gdlgstream.hpp
@@ -199,7 +199,7 @@ public:
     const char **devnames = NULL;
 #endif
 
-    static vector<std::string> devNames;
+    static std::vector<std::string> devNames;
 
     // do only once
     if( devNames.empty())
