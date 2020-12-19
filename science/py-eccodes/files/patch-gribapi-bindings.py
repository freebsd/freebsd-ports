--- gribapi/bindings.py.orig	2020-10-15 15:56:17 UTC
+++ gribapi/bindings.py
@@ -34,7 +34,7 @@ except ModuleNotFoundError:
         + pkgutil.get_data(__name__, "eccodes.h").decode("utf-8")
     )
 
-    LIBNAMES = ["eccodes", "libeccodes.so", "libeccodes"]
+    LIBNAMES = ["libeccodes.so"]
 
     try:
         import ecmwflibs
@@ -46,7 +46,6 @@ except ModuleNotFoundError:
     if os.environ.get("ECCODES_DIR"):
         eccdir = os.environ["ECCODES_DIR"]
         LIBNAMES.insert(0, os.path.join(eccdir, "lib/libeccodes.so"))
-        LIBNAMES.insert(0, os.path.join(eccdir, "lib64/libeccodes.so"))
 
     for libname in LIBNAMES:
         try:
