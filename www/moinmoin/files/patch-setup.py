--- setup.py.orig    Sun Nov  9 16:00:45 2003
+++ setup.py       Sun Dec  7 01:04:52 2003
@@ -167,10 +167,10 @@
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

