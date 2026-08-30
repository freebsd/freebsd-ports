--- examples/tennis/Tennis.cpp.orig	2026-08-25 01:40:20 UTC
+++ examples/tennis/Tennis.cpp
@@ -23,7 +23,7 @@ std::filesystem::path resourcesDir()
 #ifdef SFML_SYSTEM_IOS
     return "";
 #else
-    return "resources";
+    return "%%DATADIR%%";
 #endif
 }
 } // namespace
