--- setup.py.orig	2008-05-29 12:04:28.000000000 +0000
+++ setup.py	2008-05-29 12:04:42.000000000 +0000
@@ -73,7 +73,7 @@
     from numpy.distutils.misc_util import get_numpy_include_dirs
     _pycdf_ext = Extension(extName, 
                            sources   = CCode,
-                           #library_dirs=["non standard path where libs live"],
+                           library_dirs=["/usr/local/lib"],
                            include_dirs = get_numpy_include_dirs(), 
                            libraries = ["netcdf"])
 
