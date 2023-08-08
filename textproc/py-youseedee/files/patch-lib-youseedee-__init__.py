--- lib/youseedee/__init__.py.orig	2020-10-06 16:13:22 UTC
+++ lib/youseedee/__init__.py
@@ -9,7 +9,7 @@ import csv
 UCD_URL = "https://unicode.org/Public/UCD/latest/ucd/UCD.zip"
 
 def ucd_dir():
-  ucddir = os.path.expanduser("~/.youseedee")
+  ucddir = "%%UCDDIR%%"
   if not os.path.isdir(ucddir):
     os.mkdir(ucddir)
   return ucddir
