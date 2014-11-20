--- third_party/sqlite/sqlite.gyp.orig	2014-10-10 09:15:32 UTC
+++ third_party/sqlite/sqlite.gyp
@@ -105,6 +105,8 @@
             'amalgamation',
             # Needed for fts2 to build.
             'src/src',
+            # FreeBSD ...
+            '<(prefix_dir)/include',
           ],
           'dependencies': [
             '../icu/icu.gyp:icui18n',
