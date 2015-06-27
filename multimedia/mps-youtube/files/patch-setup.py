--- setup.py.orig	2015-06-27 09:00:49 UTC
+++ setup.py
@@ -55,8 +55,8 @@ options = dict(
     long_description=open("README.rst").read()
 )
 
-if sys.platform.startswith('linux'):
-    # Install desktop file. Required for mpris on Ubuntu
+if sys.platform.startswith(('freebsd', 'linux')):
+    # Install desktop file. Required for mpris on FreeBSD and Ubuntu
     options['data_files'] = [('share/applications/', ['mps-youtube.desktop'])]
 
 try:
