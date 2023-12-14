--- lib/youseedee/__init__.py.orig	2023-12-13 13:22:08 UTC
+++ lib/youseedee/__init__.py
@@ -23,7 +23,7 @@ UCD_URL = "https://unicode.org/Public/UCD/latest/ucd/U
 
 
 def ucd_dir():
-    ucddir = os.path.expanduser("~/.youseedee")
+    ucddir = "%%UCDDIR%%"
     if not os.path.isdir(ucddir):
         os.mkdir(ucddir)
     return ucddir
