--- setup.py.orig	2023-05-23 13:27:00 UTC
+++ setup.py
@@ -5,10 +5,9 @@ import os
 import subprocess  # nosec
 from distutils.cmd import Command
 from distutils.command.build import build as _build
-from distutils.command.install import install as _install
 from pathlib import Path
 
-from setuptools import setup
+from setuptools import setup, find_packages
 
 BASE_DIR = os.path.dirname((os.path.abspath(__file__)))
 
@@ -71,20 +70,12 @@ class build(_build):
     ]
 
 
-class install(_install):
-    sub_commands = [
-        *_install.sub_commands,
-        ("compile_translations", None),
-        ("compile_scss", None),
-    ]
-
-
 setup(
     name="django-hijack",
     use_scm_version=True,
+    packages=find_packages(exclude=['test_app']),
     cmdclass={
         "build": build,
-        "install": install,
         "compile_translations": compile_translations,
         "compile_scss": compile_scss,
     },
