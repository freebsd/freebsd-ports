--- third_party/sqlite/sqlite.gyp.orig	2015-01-21 20:28:18 UTC
+++ third_party/sqlite/sqlite.gyp
@@ -90,6 +90,8 @@
 
           'include_dirs': [
             'amalgamation',
+            # FreeBSD ...
+            '<(prefix_dir)/include',
           ],
           'dependencies': [
             '../icu/icu.gyp:icui18n',
