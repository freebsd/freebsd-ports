--- examples/keyboard/Keyboard.cpp.orig	2026-08-25 01:39:08 UTC
+++ examples/keyboard/Keyboard.cpp
@@ -22,7 +22,7 @@ std::filesystem::path resourcesDir()
 #ifdef SFML_SYSTEM_IOS
     return "";
 #else
-    return "resources";
+    return "%%DATADIR%%";
 #endif
 }
 
