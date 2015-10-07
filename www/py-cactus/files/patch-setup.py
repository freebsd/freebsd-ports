--- setup.py.orig	2015-04-05 13:19:03 UTC
+++ setup.py
@@ -118,7 +118,7 @@ setup(
         ],
     },
     install_requires=[
-        'Django==1.5.5',
+        'Django>=1.5.5,<1.7',
         'markdown2',
         'argparse',
         'keyring',
@@ -132,8 +132,8 @@ setup(
         'Mac Native FSEvents': ['macfsevents'],
     },
     zip_safe=False,
-    setup_requires=['nose'],
-    tests_require=['nose', 'mock', 'tox', 'unittest2'],
+    tests_require=['nose', 'mock', 'unittest2'],
+    test_suite="nose.collector",
     classifiers=[
         "Development Status :: 4 - Beta",
         "Environment :: Console",
