--- setup.py.orig	2018-03-17 04:34:49 UTC
+++ setup.py
@@ -40,7 +40,7 @@ setup(
     keywords='Open Science Framework PsychoPy',
     packages=find_packages(exclude=['docs', 'tests']),
     # $ pip install -e .[dev,test]
-    setup_requires=['pytest-runner', 'requests'],
+    setup_requires=['requests'],
     tests_require=['pytest', 'coverage', 'requests'],
     package_data={
         'sample': ['package_data.dat'],
