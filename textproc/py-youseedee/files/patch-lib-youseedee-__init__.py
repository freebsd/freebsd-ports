--- lib/youseedee/__init__.py.orig	2024-09-11 19:36:00 UTC
+++ lib/youseedee/__init__.py
@@ -38,7 +38,7 @@ def ucd_dir():
 
 def ucd_dir():
     """Return the directory where Unicode data is stored"""
-    ucddir = expanduser("~/.youseedee")
+    ucddir = "%%UCDDIR%%"
     try:
         os.mkdir(ucddir)
     except FileExistsError:
