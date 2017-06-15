--- setup.py.orig	2017-02-07 04:50:20 UTC
+++ setup.py
@@ -31,7 +31,6 @@ def get_data_files():
     data_files = [
         ('share/doc/glances', ['AUTHORS', 'COPYING', 'NEWS', 'README.rst',
                                'CONTRIBUTING.md', 'conf/glances.conf']),
-        ('share/man/man1', ['docs/man/glances.1'])
     ]
 
     return data_files
