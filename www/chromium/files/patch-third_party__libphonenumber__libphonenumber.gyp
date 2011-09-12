--- third_party/libphonenumber/libphonenumber.gyp.orig	2011-09-11 22:49:01.224163225 +0300
+++ third_party/libphonenumber/libphonenumber.gyp	2011-09-11 22:50:12.446499446 +0300
@@ -14,8 +14,6 @@
       'cpp/src',
       '<(protoc_out_dir)',
       '../protobuf/src',
-      '../icu/public/common',
-      '../icu/public/i18n',
     ],
     'defines': [
       'U_USING_ICU_NAMESPACE=0',
@@ -26,6 +24,12 @@
           'U_STATIC_IMPLEMENTATION',
         ],
       }],
+      ['use_system_icu == 0', {
+        'include_dirs': [
+          '../icu/public/common',
+          '../icu/public/i18n',
+        ],
+      }],
     ],
   },
   'targets': [{
