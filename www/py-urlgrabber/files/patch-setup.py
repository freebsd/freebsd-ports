--- setup.py	2005-03-08 23:53:20.000000000 +0100
+++ setup.py.port	2007-09-22 17:12:58.000000000 +0200
@@ -1,4 +1,5 @@
 # urlgrabber distutils setup
+import os
 import re as _re
 import urlgrabber as _urlgrabber
 
@@ -15,7 +16,8 @@
 packages = ['urlgrabber']
 package_dir = {'urlgrabber':'urlgrabber'}
 scripts = ['scripts/urlgrabber']
-data_files = [('share/doc/' + name + '-' + version,
+if not os.getenv('NOPORTDOCS'):
+    data_files = [('%%DOCSDIR%%',
                ['README','LICENSE', 'TODO', 'ChangeLog'])]
 options = { 'clean' : { 'all' : 1 } }
 classifiers = [
