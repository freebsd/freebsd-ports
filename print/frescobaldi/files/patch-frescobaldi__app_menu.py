--- frescobaldi_app/menu.py.orig	2016-04-21 23:00:30 UTC
+++ frescobaldi_app/menu.py
@@ -23,11 +23,12 @@ Frescobaldi main menu.
 
 from __future__ import unicode_literals
 
-try:
+import sys
+if sys.version_info >= (3, 0):
     import builtins # py3
-except ImportError:
+else:
     import __builtin__ as builtins # py2
-
+    
 from PyQt4.QtCore import QSettings
 from PyQt4.QtGui import QMenu
 
