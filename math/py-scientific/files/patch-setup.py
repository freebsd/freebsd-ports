--- setup.py.orig	2008-10-28 22:31:44.000000000 +0900
+++ setup.py	2009-01-18 12:49:38.000000000 +0900
@@ -76,7 +76,7 @@
     except KeyError:
         pass
 if netcdf_prefix is None:
-    for netcdf_prefix in ['/usr/local', '/usr', '/sw']:
+    for netcdf_prefix in [sys.prefix, '/usr', '/sw']:
         netcdf_include = os.path.join(netcdf_prefix, 'include')
         netcdf_lib = os.path.join(netcdf_prefix, 'lib')
         if os.path.exists(os.path.join(netcdf_include, 'netcdf.h')):
