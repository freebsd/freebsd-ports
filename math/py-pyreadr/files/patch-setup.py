--- setup.py.orig	2025-11-25 15:31:48 UTC
+++ setup.py
@@ -42,7 +42,6 @@ librdata_source_files = []
     return False
 
 librdata_source_files = []
-librdata_source_files += glob.glob('pyreadr/libs/librdata/src/*.c')
 librdata_source_files += ['pyreadr/librdata.pyx']
 
 library_dirs = []
@@ -78,7 +77,7 @@ elif platform.system() == 'Windows':
     libraries.append('bz2')
     libraries.append('lzma')
     
-elif platform.system() == 'Linux':
+elif platform.system() == 'FreeBSD':
     libraries.append('z')
     libraries.append('bz2')
     libraries.append('lzma')
