--- docs/userguide/genuserguide.py.orig	2022-06-08 08:27:36 UTC
+++ docs/userguide/genuserguide.py
@@ -8,7 +8,8 @@ def run(pagesize=None, verbose=0, outDir=None):
 """
 
 def run(pagesize=None, verbose=0, outDir=None):
-    import sys,os
+    import sys,os,site
+    site.addsitedir("%%STAGEDIR%%%%PYTHON_SITELIBDIR%%")
     from reportlab.lib.utils import open_and_read
     cwd = os.getcwd()
     docsDir=os.path.dirname(os.path.dirname(sys.argv[0]) or cwd)
