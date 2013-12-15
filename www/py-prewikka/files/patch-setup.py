--- setup.py.orig	2013-12-13 13:00:13.747424982 -0200
+++ setup.py	2013-12-13 13:01:10.453423405 -0200
@@ -27,9 +27,9 @@
 from distutils.dist import Distribution
 from distutils.core import setup
 from distutils.command.build import build
-from distutils.command.build_py import build_py
-from distutils.command.install import install
-from distutils.command.install_scripts import install_scripts
+from setuptools.command.build_py import build_py
+from setuptools.command.install import install
+from setuptools.command.install_scripts import install_scripts
 from distutils.command.install_data import install_data
 from distutils.core import Command
 
