Fallback to pillow_heif if pi_heif is not present.

--- src/ocrmypdf/_pipeline.py.orig	2024-06-15 08:09:59 UTC
+++ src/ocrmypdf/_pipeline.py
@@ -45,8 +45,12 @@ except ImportError:
     from pi_heif import register_heif_opener
 except ImportError:
 
-    def register_heif_opener():
-        pass
+    try:
+        from pillow_heif import register_heif_opener
+    except ImportError:
+
+        def register_heif_opener():
+            pass
 
 
 T = TypeVar("T")
