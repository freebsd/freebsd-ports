--- setup.py~	Fri Jul  4 11:50:18 2003
+++ setup.py	Fri Jul  4 11:51:08 2003
@@ -14,7 +14,7 @@
     try:
         netcdf_prefix=os.environ['NETCDF_PREFIX']
     except KeyError:
-        for netcdf_prefix in ['/usr/local', '/usr']:
+        for netcdf_prefix in [sys.prefix, '/usr']:
             netcdf_include = os.path.join(netcdf_prefix, 'include')
             netcdf_lib = os.path.join(netcdf_prefix, 'lib')
             if os.path.exists(os.path.join(netcdf_include, 'netcdf.h')):
