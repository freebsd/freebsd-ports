--- setup.py.orig	2014-12-20 17:43:35 UTC
+++ setup.py
@@ -119,5 +119,5 @@ setup(
         'Programming Language :: Python',
     ],
     package_dir={'plaso': 'plaso'},
-    packages=find_packages('.'),
+    packages=find_packages('.', exclude=['test_data', 'tools']),
 )
