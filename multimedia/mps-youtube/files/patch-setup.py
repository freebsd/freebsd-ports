--- setup.py.orig	2017-04-14 10:08:47 UTC
+++ setup.py
@@ -64,8 +64,8 @@ options = dict(
     long_description=open("README.rst").read()
 )
 
-if sys.platform.startswith('linux'):
-    # Install desktop file. Required for mpris on Ubuntu
+if sys.platform.startswith(('freebsd','linux')):
+    # Install desktop file. Required for mpris on FreeBSD and Ubuntu
     options['data_files'] = [('share/applications/', ['mps-youtube.desktop'])]
 
 if os.name == "nt":
