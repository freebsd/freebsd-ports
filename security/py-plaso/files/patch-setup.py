--- ./setup.py.orig	2014-05-25 08:56:12.000000000 +0000
+++ ./setup.py	2014-06-06 12:47:49.000000000 +0000
@@ -106,5 +106,5 @@
         'Programming Language :: Python',
     ],
     package_dir={'plaso': 'plaso'},
-    packages=find_packages('.'),
+    packages=find_packages('.', exclude=['test_data', 'tools']),
 )
