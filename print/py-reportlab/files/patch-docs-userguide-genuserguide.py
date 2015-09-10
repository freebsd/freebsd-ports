--- docs/userguide/genuserguide.py.orig	2014-02-14 14:22:37 UTC
+++ docs/userguide/genuserguide.py
@@ -8,7 +8,8 @@ This module contains the script for buil
 """
 
 def run(pagesize=None, verbose=0, outDir=None):
-    import sys,os
+    import sys,os,site
+    site.addsitedir("%%STAGEDIR%%%%PYTHON_SITELIBDIR%%")
     from reportlab.lib.utils import open_and_read, asUnicode
     cwd = os.getcwd()
     docsDir=os.path.dirname(os.path.dirname(sys.argv[0]) or cwd)
