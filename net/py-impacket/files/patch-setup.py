--- ./setup.py.orig	2013-05-08 13:57:03.000000000 +0000
+++ ./setup.py	2013-05-08 13:57:03.000000000 +0000
@@ -21,7 +21,5 @@
       platforms = ["Unix","Windows"],
       packages = ['impacket', 'impacket.dcerpc', 'impacket.examples'],
       scripts = glob.glob(os.path.join('examples', '*.py')),
-      data_files = [(os.path.join('share', 'doc', PACKAGE_NAME),
-                     ['README', 'LICENSE']+glob.glob('doc/*'))],
 
       )
