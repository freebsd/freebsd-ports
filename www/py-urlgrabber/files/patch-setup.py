--- setup.py	2005-03-08 23:53:20.000000000 +0100
+++ setup.py.port	2008-07-03 17:30:05.000000000 +0200
@@ -1,3 +1,4 @@
+
 # urlgrabber distutils setup
 import re as _re
 import urlgrabber as _urlgrabber
@@ -15,8 +16,6 @@
 packages = ['urlgrabber']
 package_dir = {'urlgrabber':'urlgrabber'}
 scripts = ['scripts/urlgrabber']
-data_files = [('share/doc/' + name + '-' + version,
-               ['README','LICENSE', 'TODO', 'ChangeLog'])]
 options = { 'clean' : { 'all' : 1 } }
 classifiers = [
         'Development Status :: 4 - Beta',
@@ -41,5 +40,9 @@
     #print '%-20s -> %s' % (k, config[k])
     if k.startswith('_'): del config[k]
 
+  import os
+  if os.environ.has_key('INSTALL_DOCS'):
+    config.setdefault('data_files', [('%%DOCSDIR%%', ['README','LICENSE', 'TODO', 'ChangeLog'])])
+
   from distutils.core import setup
   setup(**config)
