--- ./setup.py.orig	2013-04-28 18:06:57.000000000 +0000
+++ ./setup.py	2013-04-28 18:07:08.000000000 +0000
@@ -18,6 +18,4 @@
       maintainer_email = "bethus@gmail.com",
       packages = ['impacket', 'impacket.dcerpc', 'impacket.examples'],
       scripts = glob.glob(os.path.join('examples', '*.py')),
-      data_files = [(os.path.join('share', 'doc', PACKAGE_NAME),
-                     ['README', 'LICENSE']+glob.glob('doc/*'))],
       )
