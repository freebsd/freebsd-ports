--- frescobaldi_app/po/__init__.py.orig	2016-04-21 23:00:30 UTC
+++ frescobaldi_app/po/__init__.py
@@ -21,9 +21,10 @@
 Internationalization of Frescobaldi.
 """
 
-try:
+import sys
+if sys.version_info >= (3, 0):
     import builtins # py3
-except ImportError:
+else:
     import __builtin__ as builtins # py2
 
 import os
