--- ./setup.py.orig	2013-06-28 18:07:26.000000000 -0300
+++ ./setup.py	2013-11-27 17:04:07.589319517 -0200
@@ -27,7 +27,6 @@
 from distutils.unixccompiler import UnixCCompiler
 from setuptools import find_packages, setup
 from setuptools.extension import Extension
-import distribute_setup
 import glob
 import os
 import platform
@@ -370,8 +369,8 @@
             # otherwise we just use the original compile method
             UnixCCompiler.linker_so = None
             return self._original_compile(obj, src, *args, **kwargs)
-        UnixCCompiler.linker_so = ["gfortran"]
-        self.compiler_so = ["gfortran"]
+        UnixCCompiler.linker_so = ["gfortran46"]
+        self.compiler_so = ["gfortran46"]
         cc_args = ['-c', '-fno-underscoring']
         cc_args.append('-fPIC')
         try:
@@ -629,8 +628,6 @@
 
 
 def setupPackage(gfortran=True, ccompiler=True):
-    # automatically install distribute if the user does not have it installed
-    distribute_setup.use_setuptools()
     # use lib2to3 for Python 3.x
     if sys.version_info[0] == 3:
         convert2to3()
