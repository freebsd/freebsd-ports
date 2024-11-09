- https://github.com/pytorch/vision/issues/8715

--- setup.py.orig	2024-11-07 08:59:48 UTC
+++ setup.py
@@ -228,7 +228,7 @@ def find_libpng():
 
         library_dir = str(pngfix_dir / "lib")
         include_dir = str(pngfix_dir / "include/libpng16")
-        library = "libpng"
+        library = "png"
 
     return True, include_dir, library_dir, library
 
