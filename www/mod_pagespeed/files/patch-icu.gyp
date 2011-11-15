Index: third_party/icu/icu.gyp
===================================================================
--- third_party/icu/icu.gyp	(revision 2013)
+++ third_party/icu/icu.gyp	(working copy)
@@ -306,6 +306,9 @@
             'defines': [
               'USE_SYSTEM_ICU',
             ],
+        'include_dirs': [
+          '/usr/local/include',
+        ],
           },
           'link_settings': {
             'ldflags': [
