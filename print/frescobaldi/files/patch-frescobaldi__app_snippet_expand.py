--- frescobaldi_app/snippet/expand.py.orig	2016-04-21 23:00:30 UTC
+++ frescobaldi_app/snippet/expand.py
@@ -23,9 +23,10 @@ Expand variables like $DATE, $LILYPOND_V
 
 from __future__ import unicode_literals
 
-try:
+import sys
+if sys.version_info >= (3, 0):
     import builtins # py3
-except ImportError:
+else:
     import __builtin__ as builtins # py2
 
 import time
