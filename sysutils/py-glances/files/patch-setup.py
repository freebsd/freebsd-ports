--- setup.py.orig	2016-09-11 09:08:21 UTC
+++ setup.py
@@ -26,7 +26,6 @@ def get_data_files():
     data_files = [
         ('share/doc/glances', ['AUTHORS', 'COPYING', 'NEWS', 'README.rst',
                                'conf/glances.conf']),
-        ('share/man/man1', ['docs/man/glances.1'])
     ]
 
     return data_files
