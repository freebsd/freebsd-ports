--- setup.py.orig	Tue Sep 12 22:27:29 2000
+++ setup.py	Mon Sep 18 10:00:53 2000
@@ -22,9 +22,17 @@
 
 
 # Locate the directories in which the BLAS and LAPACK are located.
-# if you know where they are, put it here:
-BLASLIBDIR = None
-LAPACKLIBDIR = None  
+# if you know where they are, pass them via your environment or edit
+# the except: case.
+try:
+    BLASLIBDIR = os.environ['BLASLIBDIR']
+except KeyError:
+    BLASLIBDIR = None
+try:
+    LAPACKLIBDIR = os.environ['LAPACKLIBDIR']
+except KeyError:
+    LAPACKLIBDIR = None
+
 # places to look and what to look for
 POSSIBLE_DIRECTORIES = ['/usr/local/lib', '/usr/lib', 'lapack_lite']
 if sys.platform == 'win32':
@@ -91,7 +99,7 @@
                       Extension('umath', ['Src/umathmodule.c']),
                       Extension('lapack_lite',
                                 ['Src/lapack_litemodule.c'],
-                                libraries=['lapack', 'blas'],
+                                libraries=['lapack', 'blas', 'g2c'],
                                 library_dirs=[BLASLIBDIR, LAPACKLIBDIR]),
                       Extension('ranlib',
                                 ['Src/ranlibmodule.c',
