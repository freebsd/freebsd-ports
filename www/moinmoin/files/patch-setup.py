--- setup.py.orig	Tue Mar 12 09:25:00 2002
+++ setup.py	Tue Mar 12 09:26:47 2002
@@ -157,10 +157,10 @@
     'data_files': [
         ('share/moin/cgi-bin',
             glob.glob('wiki/cgi-bin/*.cgi') +
-            glob.glob('wiki/cgi-bin/*.py')  ),
+            glob.glob('wiki/cgi-bin/*.py.default')  ),
         ('share/moin/data',
             ['wiki/data/intermap.txt']),
-        ('share/moin/data/text',
+        ('share/moin/data/text.default',
             filter(pagefile_filter, glob.glob('wiki/data/text/*'))),
         ('share/moin/data/backup', []),
         ('share/moin/data/cache', []),
