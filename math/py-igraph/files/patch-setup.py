--- setup.py.orig	2025-06-11 00:02:53 UTC
+++ setup.py
@@ -280,8 +280,8 @@ class IgraphCCoreCMakeBuilder:
             args.append("-DIGRAPH_GRAPHML_SUPPORT:BOOL=OFF")
 
         # Build the Python interface with vendored libraries
-        for deps in "ARPACK BLAS GLPK GMP LAPACK PLFIT".split():
-            args.append("-DIGRAPH_USE_INTERNAL_" + deps + "=ON")
+        for deps in "ARPACK BLAS GLPK GMP LAPACK".split():
+            args.append("-DIGRAPH_USE_INTERNAL_" + deps + "=OFF")
 
         # Use link-time optinization if available
         args.append("-DIGRAPH_ENABLE_LTO=AUTO")
@@ -293,6 +293,12 @@ class IgraphCCoreCMakeBuilder:
         # No need to build tests
         args.append("-DBUILD_TESTING=OFF")
 
+        # Always use flex from ports
+        args.append("-DFLEX_EXECUTABLE:FILEPATH=%%LOCALBASE%%/bin/flex")
+	
+        # Don't try to use git
+        args.append("-DCMAKE_DISABLE_FIND_PACKAGE_Git:BOOL=True")
+        
         # Do not treat compilation warnings as errors in case someone is trying
         # to "pip install" igraph in an environment for which we don't provide
         # wheels and the compiler complains about harmless things
