--- setup.py.orig	2026-07-15 11:06:05 UTC
+++ setup.py
@@ -1,6 +1,9 @@ from setuptools.command.build_ext import build_ext
 from setuptools import setup, find_packages, Extension
 from setuptools.command.build_ext import build_ext
-from setuptools.command.bdist_wheel import bdist_wheel
+try:
+    from setuptools.command.bdist_wheel import bdist_wheel
+except:
+    from wheel.bdist_wheel import bdist_wheel
 from distutils.command.clean import clean
 import os
 import platform
