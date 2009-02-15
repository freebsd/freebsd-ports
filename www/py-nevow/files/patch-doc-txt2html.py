--- doc/txt2html.py	2005-02-17 18:17:23.000000000 +0100
+++ doc/txt2html.py.port	2009-02-15 09:58:17.000000000 +0100
@@ -1,7 +1,8 @@
 import sys
 import os
 import time
-
+
+sys.path.append('%%PYTHONPREFIX_SITELIBDIR%%')
 from nevow import flat, tags as T
 
 import hier
