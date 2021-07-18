--- setup.py.orig	2021-06-07 06:47:51 UTC
+++ setup.py
@@ -13,7 +13,6 @@ from setuptools import setup, Extension
 from Cython.Build import cythonize
 
 librdata_source_files = []
-librdata_source_files += glob.glob('pyreadr/libs/librdata/src/*.c')
 librdata_source_files += ['pyreadr/librdata.pyx']
 
 library_dirs = []
@@ -52,10 +51,11 @@ elif platform.system() == 'Windows':
     libraries.append('bz2')
     libraries.append('lzma')
     
-elif platform.system() == 'Linux':
+elif platform.system() == 'FreeBSD' or platform.system() == 'Linux':
     libraries.append('z')
     libraries.append('bz2')
     libraries.append('lzma')
+    libraries.append('rdata')
     #extra_compile_args.append("--std=gnu99")
 else:
     raise RuntimeError('Unsupported OS')
