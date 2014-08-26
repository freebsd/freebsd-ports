--- ./third_party/sqlite/sqlite.gyp.orig	2014-08-20 21:03:05.000000000 +0200
+++ ./third_party/sqlite/sqlite.gyp	2014-08-22 15:06:27.000000000 +0200
@@ -105,6 +105,8 @@
             'amalgamation',
             # Needed for fts2 to build.
             'src/src',
+            # FreeBSD ...
+            '<(prefix_dir)/include',
           ],
           'dependencies': [
             '../icu/icu.gyp:icui18n',
