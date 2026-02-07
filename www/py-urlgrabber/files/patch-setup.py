--- setup.py.orig	2019-02-25 13:49:04 UTC
+++ setup.py
@@ -1,4 +1,5 @@
 # urlgrabber distutils setup
+import os
 import re as _re
 import sys as _sys
 
@@ -32,9 +33,12 @@ packages = ['urlgrabber']
 package_dir = {'urlgrabber':'urlgrabber'}
 scripts = ['scripts/urlgrabber']
 data_files = [
-    ('share/doc/' + name + '-' + version, ['README','LICENSE', 'TODO', 'ChangeLog']),
     ('libexec', ['scripts/urlgrabber-ext-down']),
 ]
+if (sys.version_info.major == 2 and os.environ.has_key('INSTALL_DOCS')) or \
+        (sys.version_info.major == 3 and os.environ.get('INSTALL_DOCS')):
+    data_files.append(('%%DOCSDIR%%', ['README', 'TODO', 'ChangeLog']))
+
 setup_requires = ['six']
 install_requires = ['pycurl', 'six']
 options = { 'clean' : { 'all' : 1 } }
