--- spglib/spglib.py.orig	2024-02-11 17:45:53 UTC
+++ spglib/spglib.py
@@ -46,17 +46,17 @@ except ImportError:
     import re
     from ctypes import cdll
 
-    bundled_lib = next(
-        filter(
-            lambda fl: re.match(".*symspg\\..*", fl),
-            sorted(os.listdir(os.path.dirname(__file__))),
-        ),
-        None,
-    )
-    if not bundled_lib:
-        raise FileNotFoundError(
-            "Spglib C library is not installed and no bundled version was detected"
-        )
+    #bundled_lib = next(
+    #    filter(
+    #        lambda fl: re.match(".*symspg\\..*", fl),
+    #        sorted(os.listdir(os.path.dirname(__file__))),
+    #    ),
+    #    None,
+    #)
+    #if not bundled_lib:
+    #    raise FileNotFoundError(
+    #        "Spglib C library is not installed and no bundled version was detected"
+    #    )
     cdll.LoadLibrary(os.path.join(os.path.dirname(__file__), bundled_lib))
     from spglib import _spglib as spg  # type: ignore[attr-defined]
 
