--- serpentine/common.py.orig	Sat Jun 25 12:39:33 2005
+++ serpentine/common.py	Sat Jun 25 12:40:00 2005
@@ -111,9 +111,9 @@
     
     # Now check if cache location is ok
     try:
-        s = os.statvfs (preferences.temporary_dir)
+        s = os.statvfs ("/var/tmp")
         # Raise exception if temporary dir is not ok
-        assert preferences.temporary_dir_is_ok
+        # assert preferences.temporary_dir_is_ok
     except OSError, AssertionError:
         raise SerpentineCacheError (SerpentineCacheError.INVALID, "Please "    \
                                     "check if the cache location exists and "  \
