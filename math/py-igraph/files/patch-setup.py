--- setup.py.orig	2023-07-13 11:49:16 UTC
+++ setup.py
@@ -281,7 +281,7 @@ class IgraphCCoreCMakeBuilder:
 
         # Build the Python interface with vendored libraries
         for deps in "ARPACK BLAS GLPK GMP LAPACK".split():
-            args.append("-DIGRAPH_USE_INTERNAL_" + deps + "=ON")
+            args.append("-DIGRAPH_USE_INTERNAL_" + deps + "=OFF")
 
         # -fPIC is needed on Linux so we can link to a static igraph lib from a
         # Python shared library
@@ -289,6 +289,12 @@ class IgraphCCoreCMakeBuilder:
 
         # No need to build tests
         args.append("-DBUILD_TESTING=OFF")
+
+        # Always use flex from ports
+        args.append("-DFLEX_EXECUTABLE:FILEPATH=%%LOCALBASE%%/bin/flex")
+	
+        # Don't try to use git
+        args.append("-DCMAKE_DISABLE_FIND_PACKAGE_Git:BOOL=True")
         
         # Do not treat compilation warnings as errors in case someone is trying
         # to "pip install" igraph in an environment for which we don't provide
