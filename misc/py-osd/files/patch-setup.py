--- setup.py.orig	Thu Jan 27 15:46:22 2005
+++ setup.py	Sat Feb 26 18:43:15 2005
@@ -8,9 +8,11 @@
        url = "http://repose.cx/pyosd/",
        author = "Damien Elmes",
        author_email = "pyosd@repose.cx",
+       include_dirs = ['/usr/X11R6/include'],
        packages = ['pyosd'],
        ext_modules = \
        [Extension("_pyosd", ["_pyosd.c"],
-                  libraries=["xosd"])]
+                  libraries=["xosd"],
+                  library_dirs = ['/usr/X11R6/lib'])]
       )
 
