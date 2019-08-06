--- third_party/gpus/rocm_configure.bzl.orig	2019-06-18 23:48:23.000000000 +0100
+++ third_party/gpus/rocm_configure.bzl	2019-07-06 21:35:41.445803000 +0100
@@ -308,7 +308,7 @@
     Returns:
       The platform-specific name of the library.
     """
-    if cpu_value in ("Linux"):
+    if cpu_value in ("Linux", "FreeBSD"):
         if static:
             return "lib%s.a" % lib
         else:
