--- setup.py.orig	Mon Oct 18 08:34:00 2004
+++ setup.py	Fri Feb 24 15:33:58 2006
@@ -14,7 +14,7 @@
     try:
         netcdf_prefix=os.environ['NETCDF_PREFIX']
     except KeyError:
-        for netcdf_prefix in ['/usr/local', '/usr', '/sw']:
+        for netcdf_prefix in [sys.prefix, '/usr', '/sw']:
             netcdf_include = os.path.join(netcdf_prefix, 'include')
             netcdf_lib = os.path.join(netcdf_prefix, 'lib')
             if os.path.exists(os.path.join(netcdf_include, 'netcdf.h')):
