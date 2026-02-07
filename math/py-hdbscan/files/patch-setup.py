--- setup.py.orig	2023-07-18 17:51:04 UTC
+++ setup.py
@@ -85,7 +85,7 @@ configuration = {
     'cmdclass': {'build_ext': CustomBuildExtCommand},
     'test_suite': 'nose.collector',
     'tests_require': ['nose'],
-    'data_files': ('hdbscan/dist_metrics.pxd',)
+    'package_data': {'': ['hdbscan/dist_metrics.pxd']},
 }
 
 if not HAVE_CYTHON:
