--- src/extractcode/libarchive2.py.orig	2018-10-15 13:51:18 UTC
+++ src/extractcode/libarchive2.py
@@ -101,6 +101,7 @@ def load_lib():
     # get paths from plugins
     dll = get_location(EXTRACTCODE_LIBARCHIVE_DLL)
     libdir = get_location(EXTRACTCODE_LIBARCHIVE_LIBDIR)
+    dll = libdir
     return command.load_shared_library(dll, libdir)
 
 
