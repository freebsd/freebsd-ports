--- src/Dirstructure.cpp.orig	2025-04-27 13:21:48 UTC
+++ src/Dirstructure.cpp
@@ -121,6 +121,7 @@ wxString Dirstructure::ResourcesDir() {
     exepath = exe.GetPath();
   } else {
     exepath = CMAKE_INSTALL_PREFIX;
+    exepath.Append("/share");
   }
   return exepath;
 }
