--- ./setup.py.orig	2013-10-31 18:02:07.000000000 +0000
+++ ./setup.py	2014-01-26 09:42:25.000000000 +0000
@@ -104,7 +104,7 @@
           'Programming Language :: Python',
       ],
       #include_package_data=True,
-      packages=find_packages('.'),
+      packages=find_packages('.', exclude=['test_data']),
       package_data={'plaso.test_data': GetFileList('test_data', ['*'])},
      )
 
