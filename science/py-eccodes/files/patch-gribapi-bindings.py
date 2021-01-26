--- gribapi/bindings.py.orig	2021-01-20 16:01:53 UTC
+++ gribapi/bindings.py
@@ -33,7 +33,7 @@ except ModuleNotFoundError:
     CDEF += pkgutil.get_data(__name__, "eccodes.h")
     ffi.cdef(CDEF.decode("utf-8").replace("\r", "\n"))
 
-    LIBNAMES = ["eccodes", "libeccodes.so", "libeccodes"]
+    LIBNAMES = ["libeccodes.so"]
 
     try:
         import ecmwflibs
@@ -45,7 +45,6 @@ except ModuleNotFoundError:
     if os.environ.get("ECCODES_DIR"):
         eccdir = os.environ["ECCODES_DIR"]
         LIBNAMES.insert(0, os.path.join(eccdir, "lib/libeccodes.so"))
-        LIBNAMES.insert(1, os.path.join(eccdir, "lib64/libeccodes.so"))
 
     lib = None
     for libname in LIBNAMES:
