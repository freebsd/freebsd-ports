Add extra machinery to pass arguments to CMake; this is FreeBSD-specific
until CMake's FindBoost understands FreeBSD-suffixed Boost::Python versions.

Also leave the build directory intact.

--- setup.py.orig	2017-08-28 22:18:45 UTC
+++ setup.py
@@ -91,6 +91,8 @@ def _get_options():
         elif opt_key == 'G':
             _cmake_extra += ['-G', arg.strip()]
             _generator_set = True
+        elif opt_key == 'cmake-extra':
+            _cmake_extra.append('-D{arg}'.format(arg=arg.strip()))
 
         if opt_key:
             sys.argv.remove(arg)
@@ -112,7 +114,7 @@ def _get_options():
             opt_key = opt
             sys.argv.remove(arg)
             continue
-        elif opt in ['yes', 'no', 'compiler-flags']:
+        elif opt in ['yes', 'no', 'compiler-flags', 'cmake-extra']:
             opt_key = opt
             sys.argv.remove(arg)
             continue
@@ -548,9 +550,6 @@ class build(_build):
                     break
 
         build_dir = os.path.join(script_dir, "./tools/python/build")
-        if os.path.exists(build_dir):
-            log.info('Removing build directory %s' % build_dir)
-            rmtree(build_dir)
 
         try:
             os.makedirs(build_dir)
