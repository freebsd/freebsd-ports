--- examples/sound_effects/SoundEffects.cpp.orig	2026-08-25 01:40:03 UTC
+++ examples/sound_effects/SoundEffects.cpp
@@ -28,7 +28,7 @@ std::filesystem::path resourcesDir()
 #ifdef SFML_SYSTEM_IOS
     return "";
 #else
-    return "resources";
+    return "%%DATADIR%%";
 #endif
 }
 } // namespace
