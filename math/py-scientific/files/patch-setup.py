--- setup.py.orig	Thu Mar 29 17:08:38 2001
+++ setup.py	Mon Apr  2 18:50:48 2001
@@ -11,7 +11,7 @@
 
 
 if netcdf_prefix is None:
-    for netcdf_prefix in ['/usr/local', '/usr']:
+    for netcdf_prefix in [sys.prefix, '/usr']:
         netcdf_include = os.path.join(netcdf_prefix, 'include')
         netcdf_lib = os.path.join(netcdf_prefix, 'lib')
         if os.path.exists(os.path.join(netcdf_include, 'netcdf.h')):
