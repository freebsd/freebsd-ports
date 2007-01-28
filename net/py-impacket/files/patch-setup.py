--- Impacket-0.9.6.0/setup.py  2006-09-20 17:37:44.000000000 -0400
+++ setup.py   2006-09-20 17:48:59.000000000 -0400
@@ -17,7 +17,7 @@
       maintainer = "Max Caceres",
       maintainer_email = "max@coresecurity.com",
       packages = ['impacket', 'impacket.dcerpc'],
-      scripts = glob.glob(os.path.join('examples', '*.py'))+glob.glob('doc/*'),
+      scripts = glob.glob(os.path.join('examples', '*.py')),
       data_files = [(os.path.join('share', 'doc', PACKAGE_NAME),
-                     ['README', 'LICENSE'])],
+                     ['README', 'LICENSE']+glob.glob('doc/*'))]
       )
