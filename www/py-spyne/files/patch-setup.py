--- setup.py.orig	2016-10-28 11:15:20 UTC
+++ setup.py
@@ -3,6 +3,7 @@
 
 from __future__ import print_function
 
+import codecs
 import os
 import re
 import sys
@@ -48,7 +49,7 @@ protocols and transports.
 
 try:
     os.stat('CHANGELOG.rst')
-    LONG_DESC += "\n\n" + open('CHANGELOG.rst', 'r').read()
+    LONG_DESC += "\n\n" + codecs.open('CHANGELOG.rst', 'r', encoding='utf-8').read()
 except OSError:
     pass
 
