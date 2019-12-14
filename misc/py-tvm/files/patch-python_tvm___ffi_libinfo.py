--- python/tvm/_ffi/libinfo.py.orig	2019-11-27 03:24:12 UTC
+++ python/tvm/_ffi/libinfo.py
@@ -72,6 +72,8 @@ def find_lib_path(name=None, search_path=None, optiona
     if sys.platform.startswith('linux'):
         dll_path.extend(split_env_var('LD_LIBRARY_PATH', ':'))
         dll_path.extend(split_env_var('PATH', ':'))
+    elif sys.platform.startswith('freebsd'):
+        dll_path.extend(split_env_var('FREEBSD_LIBRARY_PATH', ':'))
     elif sys.platform.startswith('darwin'):
         dll_path.extend(split_env_var('DYLD_LIBRARY_PATH', ':'))
         dll_path.extend(split_env_var('PATH', ':'))
