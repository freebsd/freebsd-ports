--- setup.py	10 Sep 2002 13:13:11 -0000	1.1.1.1
+++ setup.py	10 Sep 2002 13:14:03 -0000	1.2
@@ -21,7 +21,7 @@
     ext = Extension('spread', ['spreadmodule.c'],
                 include_dirs = [SPREAD_DIR + "/include"],
                 library_dirs = [SPREAD_DIR + "/lib"],
-                libraries = ['tsp'],
+                libraries = ['tspread'],
                 )
 
 setup(name = "Spread API for Python",
