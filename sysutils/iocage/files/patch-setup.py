--- setup.py.orig	2026-04-29 16:39:04 UTC
+++ setup.py
@@ -61,7 +61,7 @@ setup(
     ],
     entry_points={'console_scripts': ['iocage = iocage_lib:cli']},
     data_files=_data,
-    tests_require=['pytest', 'pytest-cov', 'pytest-pep8', 'pytest-runner']
+    tests_require=['pytest', 'pytest-cov', 'pytest-runner']
 )
 
 setup(
