--- setup.py.orig	2019-06-12 18:08:59 UTC
+++ setup.py
@@ -18,12 +18,14 @@ platform_supported = False
 for prefix in ['darwin', 'linux', 'bsd']:
     if prefix in sys.platform:
         platform_supported = True
-        include_dirs = ['/usr/include',
+        include_dirs = [ '/usr/include',
+                        '/usr/local/include/fcl05',
                         '/usr/local/include',
                         '/usr/include/eigen3']
         lib_dirs = ['/usr/lib',
-                    '/usr/local/lib']
-        
+                    '/usr/local/lib/',
+                    '/usr/local/lib/']
+
         if 'CPATH' in os.environ:
             include_dirs += os.environ['CPATH'].split(':')
         if 'LD_LIBRARY_PATH' in os.environ:
@@ -78,9 +80,10 @@ setup(
         include_dirs = include_dirs,
         library_dirs = lib_dirs,
         libraries=[
-                "fcl","octomap"
+                "fcl05","octomap"
                 ],
         language="c++",
-        extra_compile_args = ["-std=c++11"]
+        extra_compile_args = ["-std=c++11"],
+        extra_link_args = ['-Wl,-rpath, '+'/usr/local/lib/fcl05']
     )]
 )
