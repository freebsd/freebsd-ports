--- src/Dirstructure.cpp.orig	2024-08-28 07:17:18 UTC
+++ src/Dirstructure.cpp
@@ -121,6 +121,7 @@ wxString Dirstructure::ResourcesDir() {
     exepath = exe.GetPath();
   } else {
     exepath = CMAKE_INSTALL_PREFIX;
+    exepath.Append("/share");
   }
   return exepath;
 }
