--- setup.py.orig	2023-04-03 09:02:01 UTC
+++ setup.py
@@ -4,7 +4,7 @@ from setuptools import setup, find_packages
 setup(
     name="shell_gpt",
     version="0.8.1",
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     install_requires=[
         "typer~=0.7.0",
         "requests~=2.28.2",
