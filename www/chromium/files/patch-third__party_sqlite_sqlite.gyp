--- third_party/sqlite/sqlite.gyp.orig	2016-05-11 19:02:34 UTC
+++ third_party/sqlite/sqlite.gyp
@@ -153,6 +153,8 @@
           },
           'include_dirs': [
             'amalgamation',
+            # FreeBSD ...
+            '<(prefix_dir)/include',
           ],
           'dependencies': [
             '../icu/icu.gyp:icui18n',
