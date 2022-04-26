--- setup.py.orig	2020-09-19 15:39:42 UTC
+++ setup.py
@@ -11,7 +11,7 @@ setup(
     author='Itay Brandes',
     author_email='brandes.itay+pysmartdl@gmail.com',
     license='Public Domain',
-    packages=find_packages(),
+    packages=find_packages(exclude=['test*']),
     description='A Smart Download Manager for Python',
     long_description=open('README.md').read(),
     test_suite = "test.test_pySmartDL.test_suite",
