--- setup.py.orig	2019-10-09 04:06:06 UTC
+++ setup.py
@@ -1,8 +1,14 @@ from setuptools import setup
 from setuptools import setup
+import os
 
 pkg_name = "urlgrabber"
 pkg_version = "4.1.0"
 
+if os.environ.get('INSTALL_DOCS'):
+    docs_files = ('%%DOCSDIR%%', ['README', 'TODO', 'ChangeLog'])
+else:
+    docs_file = None
+
 setup(
     name=pkg_name,
     version=pkg_version,
@@ -52,7 +58,8 @@ setup(
     ],
     scripts = ['scripts/urlgrabber'],
     data_files = [
-        ('share/doc/' + pkg_name + '-' + pkg_version, ['README','LICENSE', 'TODO', 'ChangeLog']),
         ('libexec', ['scripts/urlgrabber-ext-down']),
+        docs_files
    ],
+
 )
