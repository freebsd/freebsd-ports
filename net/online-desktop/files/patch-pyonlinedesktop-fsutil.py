--- pyonlinedesktop/fsutil.py~	2008-04-23 23:06:43.000000000 +0530
+++ pyonlinedesktop/fsutil.py	2008-05-28 21:27:46.000000000 +0530
@@ -12,7 +12,7 @@
   if datadir_env:
     datadirs = datadir_env.split(':')
   else:
-    datadirs = ['/usr/share/']
+    datadirs = ['%%PREFIX%%/share/']
   for dirname in datadirs:
     dirpath = os.path.join(dirname, name)
     if os.access(dirpath, os.R_OK):
