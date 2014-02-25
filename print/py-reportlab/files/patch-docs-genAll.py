--- docs/genAll.py.orig	2014-02-14 23:22:37.000000000 +0900
+++ docs/genAll.py	2014-02-16 16:20:21.000000000 +0900
@@ -1,6 +1,7 @@
 #!/bin/env python
-import os, sys, traceback
+import os, sys, traceback, site
 def _genAll(verbose=1):
+    site.addsitedir("%%STAGEDIR%%%%PYTHON_SITELIBDIR%%")
     from reportlab.lib.testutils import setOutDir
     setOutDir(__name__)
     from reportlab.lib.testutils import testsFolder
