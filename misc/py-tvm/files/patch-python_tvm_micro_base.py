--- python/tvm/micro/base.py.orig	2019-12-14 17:04:12 UTC
+++ python/tvm/micro/base.py
@@ -87,8 +87,8 @@ class Session:
 
         Raises error if not supported.
         """
-        if not sys.platform.startswith("linux"):
-            raise RuntimeError("microTVM is currently only supported on Linux")
+        if not sys.platform.startswith("linux") and not sys.platform.startswith("freebsd"):
+            raise RuntimeError("microTVM is currently only supported on Linux and FreeBSD")
         # TODO(weberlo): Add 32-bit support.
         # It's primarily the compilation pipeline that isn't compatible.
         if sys.maxsize <= 2**32:
