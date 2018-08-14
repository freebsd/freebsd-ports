--- docs/conf.py.orig	2018-04-18 12:16:19 UTC
+++ docs/conf.py
@@ -3,6 +3,8 @@ import sys
 import os
 import shlex
 
+sys.path.insert(0, os.path.abspath('../src'))
+
 extensions = [
     'sphinx.ext.autodoc',
     'sphinx.ext.intersphinx',
