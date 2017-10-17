--- testing/gtest.gyp.orig	2017-10-06 20:45:48 UTC
+++ testing/gtest.gyp
@@ -46,15 +46,20 @@
       ],
       'dependencies': [
         'gtest_prod',
+        '<(DEPTH)/third_party/gflags/gflags.gyp:gflags',
+        '<(DEPTH)/third_party/apr/apr.gyp:include',
+        '<(DEPTH)/third_party/aprutil/aprutil.gyp:include',
       ],
       'defines': [
         # In order to allow regex matches in gtest to be shared between Windows
         # and other systems, we tell gtest to always use it's internal engine.
         'GTEST_HAS_POSIX_RE=0',
+        'GTEST_HAS_DEATH_TEST=1',
       ],
       'all_dependent_settings': {
         'defines': [
           'GTEST_HAS_POSIX_RE=0',
+          'GTEST_HAS_DEATH_TEST=1',
         ],
       },
       'conditions': [
