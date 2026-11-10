-- Link the Python module against the system sentencepiece shared libraries
-- instead of the bundled cmake build, which fails against abseil 20250127+.

--- setup.py.orig	2026-11-04 06:47:28 UTC
+++ setup.py
@@ -99,8 +99,18 @@ class build_ext_unix(_build_ext):
   """Override build_extension to run cmake."""
 
   def build_extension(self, ext):
-    cflags, libs = get_cflags_and_libs('../build')
-    abseil_libs = find_abseil_lib('../build')
+    system_libs = [
+        '/usr/local/lib/libsentencepiece.so',
+        '/usr/local/lib/libsentencepiece_train.so',
+    ]
+    if all(os.path.exists(l) for l in system_libs):
+      cflags = ['-std=c++20', '-DSENTENCEPIECE_LITE_USE_ABSL', '-I/usr/local/include',
+                '-I../src', '-I../lite', '-I./gen']
+      libs = list(system_libs)
+      abseil_libs = []
+    else:
+      cflags, libs = get_cflags_and_libs('../build')
+      abseil_libs = find_abseil_lib('../build')
 
     if len(libs) == 0:
       cflags, libs = get_cflags_and_libs('./build')
