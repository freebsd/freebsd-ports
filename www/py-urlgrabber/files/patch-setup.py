--- setup.py.orig	2017-07-23 09:57:14 UTC
+++ setup.py
@@ -32,7 +32,6 @@ packages = ['urlgrabber']
 package_dir = {'urlgrabber':'urlgrabber'}
 scripts = ['scripts/urlgrabber']
 data_files = [
-    ('share/doc/' + name + '-' + version, ['README','LICENSE', 'TODO', 'ChangeLog']),
     ('libexec', ['scripts/urlgrabber-ext-down']),
 ]
 options = { 'clean' : { 'all' : 1 } }
@@ -59,5 +58,9 @@ if __name__ == '__main__':
     #print '%-20s -> %s' % (k, config[k])
     if k.startswith('_'): del config[k]
 
+  import os
+  if os.environ.has_key('INSTALL_DOCS'):
+    data_files.append(('%%DOCSDIR%%', ['README', 'TODO', 'ChangeLog']))
+
   from distutils.core import setup
   setup(**config)
