--- src/furo/__init__.py.orig	2023-09-10 14:57:28 UTC
+++ src/furo/__init__.py
@@ -347,7 +347,7 @@ def _overwrite_pygments_css(
 
 def setup(app: sphinx.application.Sphinx) -> Dict[str, Any]:
     """Entry point for sphinx theming."""
-    app.require_sphinx("6.0")
+    app.require_sphinx("5.0")
 
     app.add_config_value(
         "pygments_dark_style", default="native", rebuild="env", types=[str]
