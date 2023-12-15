--- build-aux/cs_compile_build.py.orig	2023-12-14 20:49:47 UTC
+++ build-aux/cs_compile_build.py
@@ -394,8 +394,9 @@ def get_dynamic_lib_dep_flags(pkg, top_builddir=None, 
         if libs:
             cmd_line += libs + " "
 
-    if rpath_list:
-        cmd_line += "-Wl,-rpath -Wl," + ':'.join(rpath_list)
+    # Not needed on FreeBSD, we have ldconfig, and it causes the libs to get linked against $DESTDIR
+    #if rpath_list:
+    #    cmd_line += "-Wl,-rpath -Wl," + ':'.join(rpath_list)
 
     return cmd_line.rstrip()
 
