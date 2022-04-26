--- setup.py.orig	2021-10-15 18:41:22 UTC
+++ setup.py
@@ -38,7 +38,7 @@ class VerifyVersionCommand(install):
 setup(
     name="quilt3",
     version=VERSION,
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests*']),
     description='Quilt: where data comes together',
     long_description=readme(),
     python_requires='>=3.6',
