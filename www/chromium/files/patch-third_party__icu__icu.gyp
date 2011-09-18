--- third_party/icu/icu.gyp.orig	2011-09-09 23:54:57.000000000 +0300
+++ third_party/icu/icu.gyp	2011-09-10 00:17:17.000000000 +0300
@@ -517,6 +517,9 @@
             'defines': [
               'USE_SYSTEM_ICU',
             ],
+            'include_dirs': [
+              '<!@(icu-config --prefix)/include',
+            ],
           },
           'link_settings': {
             'ldflags': [
