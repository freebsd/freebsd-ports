--- docs/userguide/genuserguide.py.orig	2014-02-14 23:22:37.000000000 +0900
+++ docs/userguide/genuserguide.py	2014-02-16 16:15:05.000000000 +0900
@@ -8,7 +8,8 @@
 """
 
 def run(pagesize=None, verbose=0, outDir=None):
-    import sys,os
+    import sys,os,site
+    site.addsitedir("%%STAGEDIR%%%%PYTHON_SITELIBDIR%%")
     from reportlab.lib.utils import open_and_read, asUnicode
     cwd = os.getcwd()
     docsDir=os.path.dirname(os.path.dirname(sys.argv[0]) or cwd)
