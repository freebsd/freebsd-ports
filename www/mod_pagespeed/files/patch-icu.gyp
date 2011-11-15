--- third_party/icu/icu.gyp.orig	Mon Oct 31 10:25:10 2011
+++ third_party/icu/icu.gyp	Tue Nov 15 14:10:17 2011
@@ -306,6 +306,9 @@
             'defines': [
               'USE_SYSTEM_ICU',
             ],
+            'cflags+': [
+              '<!@(icu-config --cppflags-searchpath)'
+            ],
           },
           'link_settings': {
             'ldflags': [
