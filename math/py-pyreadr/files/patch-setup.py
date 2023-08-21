--- setup.py.orig	2023-08-09 07:13:10 UTC
+++ setup.py
@@ -13,12 +13,7 @@ from setuptools import setup, Extension
 from Cython.Build import cythonize
 import Cython
 
-cyver = int(Cython.__version__.split(".")[0])
-if cyver < 3:
-    raise Exception("cython 3.0.0 or newer is required")
-
 librdata_source_files = []
-librdata_source_files += glob.glob('pyreadr/libs/librdata/src/*.c')
 librdata_source_files += ['pyreadr/librdata.pyx']
 
 library_dirs = []
@@ -54,7 +49,7 @@ elif platform.system() == 'Windows':
     libraries.append('bz2')
     libraries.append('lzma')
     
-elif platform.system() == 'Linux':
+elif platform.system() == 'FreeBSD':
     libraries.append('z')
     libraries.append('bz2')
     libraries.append('lzma')
