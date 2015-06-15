--- setup.py.orig	2015-06-15 02:42:15 UTC
+++ setup.py
@@ -15,8 +15,7 @@ def get_data_files():
     data_files = [
         ('share/doc/glances', ['AUTHORS', 'COPYING', 'NEWS', 'README.rst',
                                'conf/glances.conf', 'docs/glances-doc.html']),
-        ('share/doc/glances/images', glob.glob('docs/images/*.png')),
-        ('share/man/man1', ['man/glances.1'])
+        ('share/doc/glances/images', glob.glob('docs/images/*.png'))
     ]
 
     return data_files
