--- numpy/core/setup.py.orig	2016-06-25 23:59:40 UTC
+++ numpy/core/setup.py
@@ -268,7 +268,7 @@ def check_types(config_cmd, ext, build_d
         raise SystemError(
                 "Cannot compile 'Python.h'. Perhaps you need to "
                 "install python-dev|python-devel.")
-    res = config_cmd.check_header("endian.h")
+    res = config_cmd.check_header("sys/endian.h")
     if res:
         private_defines.append(('HAVE_ENDIAN_H', 1))
         public_defines.append(('NPY_HAVE_ENDIAN_H', 1))
