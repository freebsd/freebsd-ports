--- src/Dirstructure.cpp.orig	2023-02-19 14:20:34 UTC
+++ src/Dirstructure.cpp
@@ -120,6 +120,7 @@ wxString Dirstructure::ResourcesDir() const {
     exepath = exe.GetPath();
   } else {
     exepath = CMAKE_INSTALL_PREFIX;
+    exepath.Append("/share");
   }
   return exepath;
 }
