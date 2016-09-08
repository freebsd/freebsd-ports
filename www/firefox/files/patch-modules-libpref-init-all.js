--- modules/libpref/init/all.js.orig	2016-07-25 20:22:05 UTC
+++ modules/libpref/init/all.js
@@ -4453,6 +4453,11 @@ pref("layers.max-active", -1);
 // if you change the tile size.
 pref("layers.tiles.adjust", true);
 
+#ifndef MOZ_TREE_CAIRO
+// Disable for system cairo on suspicion of causing random crashes
+pref("layers.offmainthreadcomposition.force-disabled", true);
+#endif
+
 // Compositor target frame rate. NOTE: If vsync is enabled the compositor
 // frame rate will still be capped.
 // -1 -> default (match layout.frame_rate or 60 FPS)
