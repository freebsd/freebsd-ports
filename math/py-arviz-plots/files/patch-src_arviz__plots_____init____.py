-- Add arviz_darkgrid_template to the del block after the plotly templates are added to prevent namespace leakage.
--- src/arviz_plots/__init__.py.orig	2026-09-10 20:53:17 UTC
+++ src/arviz_plots/__init__.py
@@ -335,6 +335,15 @@ try:
     pio.templates["arviz-tumma"] = arviz_tumma_template
     pio.templates["arviz-darkgrid"] = arviz_darkgrid_template
 
+    del (
+        pio,
+        arviz_cetrino_template,
+        arviz_tenui_template,
+        arviz_variat_template,
+        arviz_vibrant_template,
+        arviz_tumma_template,
+        arviz_darkgrid_template,
+    )
 
 except ImportError:
     pass
