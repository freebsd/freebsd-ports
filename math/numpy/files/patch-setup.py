--- setup.py.orig	Mon Aug 28 13:49:52 2000
+++ setup.py	Thu Aug 31 17:48:46 2000
@@ -21,9 +21,17 @@
 
 
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
