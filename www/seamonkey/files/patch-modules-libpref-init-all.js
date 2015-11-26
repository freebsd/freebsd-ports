--- mozilla/modules/libpref/init/all.js.orig	2015-08-06 22:39:34 UTC
+++ mozilla/modules/libpref/init/all.js
@@ -4052,7 +4052,12 @@ pref("layers.max-active", -1);
 pref("layers.tiles.adjust", true);
 
 // Set the default values, and then override per-platform as needed
+#ifdef MOZ_TREE_CAIRO
 pref("layers.offmainthreadcomposition.enabled", true);
+#else
+// Disable for system cairo on suspicion of causing random crashes
+pref("layers.offmainthreadcomposition.enabled", false);
+#endif
 // Compositor target frame rate. NOTE: If vsync is enabled the compositor
 // frame rate will still be capped.
 // -1 -> default (match layout.frame_rate or 60 FPS)
