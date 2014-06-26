--- setup.py.orig	2013-05-25 11:00:56.000000000 +0200
+++ setup.py	2014-06-21 22:27:11.000000000 +0200
@@ -129,11 +129,21 @@
             print >>sys.stderr, 'epydoc not installed, skipping build_doc.'
 
 
-commands = {'build_doc': build_doc,
-            'install_lib': install_lib}
+commands = {'build_doc': build_doc}
 
 desc = open("README.rst").read() + "\n" + open("CHANGES.rst").read()
 
+if sys.platform[:3] == 'win':
+    platform = 'windows'
+elif sys.platform == 'darwin':
+    platform = 'darwin'
+else:
+    platform = 'posix'
+path = os.path.join('Skype4Py', 'api')
+for name in os.listdir(path):
+    if not (name.startswith('__') or name.startswith(platform)):
+        os.remove(os.path.join(path, name))
+
 # start the distutils setup
 setup(name='Skype4Py',
       version=VERSION,
