--- src/arviz_plots/__init__.py.orig	2026-04-17 17:39:26 UTC
+++ src/arviz_plots/__init__.py
@@ -330,6 +330,14 @@ try:
     pio.templates["arviz-vibrant"] = arviz_vibrant_template
     pio.templates["arviz-tumma"] = arviz_tumma_template
 
+    del (
+        pio,
+        arviz_cetrino_template,
+        arviz_tenui_template,
+        arviz_variat_template,
+        arviz_vibrant_template,
+        arviz_tumma_template,
+    )
 
 except ImportError:
     pass
