--- setup.py.orig	Sun Jun  6 08:58:33 2004
+++ setup.py	Fri Jun 25 03:31:38 2004
@@ -167,9 +167,11 @@
     'scripts': moin_scripts,
 
     'data_files': [
-        ('share/moin/cgi-bin', filter(trash_filter, glob.glob('wiki/cgi-bin/*'))),
+        ('share/moin/cgi-bin', filter(trash_filter,
+            glob.glob('wiki/cgi-bin/*.cgi') +
+            glob.glob('wiki/cgi-bin/*.py.default'))),
         ('share/moin/data', ['wiki/data/intermap.txt']),
-        ('share/moin/data/text', filter(trash_filter, glob.glob('wiki/data/text/*'))),
+        ('share/moin/data/text.default', filter(trash_filter, glob.glob('wiki/data/text/*'))),
         ('share/moin/data/plugin', ['wiki/data/plugin/__init__.py']),
         ('share/moin/data/plugin/action', ['wiki/data/plugin/action/__init__.py']),
         ('share/moin/data/plugin/macro', ['wiki/data/plugin/macro/__init__.py']),
