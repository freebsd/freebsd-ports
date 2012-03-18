--- setup.py.bak	2012-03-13 01:09:10.101266743 +0600
+++ setup.py	2012-03-13 01:11:27.277242740 +0600
@@ -1,21 +1,16 @@
 from distutils.core import setup
-import os
 
 # Please run
 # python setup.py install
 
-if os.path.exists('doc/mount.wikipediafs.1.gz'):
-    df = [('/usr/share/man/man1/', ['doc/mount.wikipediafs.1.gz'])]
-else:
-    df = []    
-
 setup(
     name = 'wikipediafs',
+    version = '0.4',
     author = 'Mathieu Blondel',
     author_email = 'mblondel@users.sourceforge.net',
     url = 'http://wikipediafs.sourceforge.net',
     packages = ['wikipediafs'],
     package_dir = {'wikipediafs':'src/wikipediafs/'},
     scripts = ['src/mount.wikipediafs'],
-    data_files = df,
-)
\ No newline at end of file
+)
+
