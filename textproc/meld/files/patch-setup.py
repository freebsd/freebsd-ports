--- setup.py.orig	2014-11-22 12:24:31 UTC
+++ setup.py
@@ -37,11 +37,11 @@ setup(
     },
     scripts=['bin/meld'],
     data_files=[
-        ('share/man/man1',
+        ('man/man1',
          ['meld.1']
          ),
-        ('share/doc/meld-' + meld.conf.__version__,
-         ['COPYING', 'NEWS']
+        ('share/doc/meld',
+         ['NEWS']
          ),
         ('share/meld',
          ['data/meld.css']
