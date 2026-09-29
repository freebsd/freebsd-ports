--- tidy/lib.py.orig	2026-01-07 12:22:38 UTC
+++ tidy/lib.py
@@ -61,6 +61,8 @@ LIBNAMES = (
     # Windows?
     "tidylib.dll",
     "tidylib",
+    # FreeBSD
+    "libtidy5.so",
 )
 
 
