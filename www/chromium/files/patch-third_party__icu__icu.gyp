--- third_party/icu/icu.gyp.orig	2011-09-11 20:07:49.787935237 +0300
+++ third_party/icu/icu.gyp	2011-09-11 20:09:30.972764759 +0300
@@ -524,6 +524,9 @@
             'defines': [
               'USE_SYSTEM_ICU',
             ],
+            'include_dirs': [
+              '<!@(icu-config --prefix)/include',
+            ],
           },
           'link_settings': {
             'ldflags': [
