--- setup.py.orig	2019-09-26 07:23:24 UTC
+++ setup.py
@@ -58,7 +58,7 @@ setup(
         'dnspython>=1.15.0',
         'libzfs'
     ],
-    setup_requires=['pytest-runner'],
+#    setup_requires=['pytest-runner'],
     entry_points={'console_scripts': ['iocage = iocage_lib:cli']},
     data_files=_data,
     tests_require=['pytest', 'pytest-cov', 'pytest-pep8']
