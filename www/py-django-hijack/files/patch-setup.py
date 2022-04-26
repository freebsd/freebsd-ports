Handle the installation by native setuptools to prevent errors like
"command 'install' has no such option 'single_version_externally_managed'".

--- setup.py.orig	2022-03-12 16:51:11 UTC
+++ setup.py
@@ -5,7 +5,6 @@ import os
 import subprocess  # nosec
 from distutils.cmd import Command
 from distutils.command.build import build as _build
-from distutils.command.install import install as _install
 
 from setuptools import setup
 
@@ -62,21 +61,11 @@ class build(_build):
         ("compile_scss", None),
     ]
 
-
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
     cmdclass={
         "build": build,
-        "install": install,
         "compile_translations": compile_translations,
         "compile_scss": compile_scss,
     },
