--- ./third_party/sqlite/sqlite.gyp.orig	2014-08-12 21:02:44.000000000 +0200
+++ ./third_party/sqlite/sqlite.gyp	2014-08-13 09:56:59.000000000 +0200
@@ -105,6 +105,8 @@
             'amalgamation',
             # Needed for fts2 to build.
             'src/src',
+            # FreeBSD ...
+            '<(prefix_dir)/include',
           ],
           'dependencies': [
             '../icu/icu.gyp:icui18n',
