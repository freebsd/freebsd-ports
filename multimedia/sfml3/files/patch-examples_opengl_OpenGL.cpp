--- examples/opengl/OpenGL.cpp.orig	2026-08-25 01:39:16 UTC
+++ examples/opengl/OpenGL.cpp
@@ -27,7 +27,7 @@ std::filesystem::path resourcesDir()
 #ifdef SFML_SYSTEM_IOS
     return "";
 #else
-    return "resources";
+    return "%%DATADIR%%";
 #endif
 }
 } // namespace
