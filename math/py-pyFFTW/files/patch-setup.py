--- setup.py.orig	2016-06-06 16:40:50 UTC
+++ setup.py
@@ -121,8 +121,8 @@ def get_libraries():
         libraries = ['libfftw3-3', 'libfftw3f-3', 'libfftw3l-3']
 
     else:
-        libraries = ['fftw3', 'fftw3f', 'fftw3l', 'fftw3_threads',
-                     'fftw3f_threads', 'fftw3l_threads']
+        libraries = ['fftw3', 'fftw3f', 'fftw3_threads',
+                     'fftw3f_threads']
 
     return libraries
 
