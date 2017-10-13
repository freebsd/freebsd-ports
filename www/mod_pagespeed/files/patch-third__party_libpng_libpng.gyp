--- third_party/libpng/libpng.gyp.orig	2017-10-04 21:29:34 UTC
+++ third_party/libpng/libpng.gyp
@@ -108,11 +108,11 @@
             # This detects the version and sets the variable to non-zero for
             # pre-1.4 versions.
             'png_free_me_suported_define_in_libpng' :
-              '<!(<(pkg-config) --atleast-version=1.4.0 libpng; echo $?)'
+              '<!(<(pkg-config) --atleast-version=1.4.0 libpng; echo $?)'
           },
           'direct_dependent_settings': {
             'cflags': [
-              '<!@(<(pkg-config) --cflags libpng)',
+              '<!@(<(pkg-config) --cflags libpng)',
             ],
             'defines+': [
               'USE_SYSTEM_LIBPNG',
@@ -135,10 +135,10 @@
           ],
           'link_settings': {
             'ldflags': [
-              '<!@(<(pkg-config) --libs-only-L --libs-only-other libpng)',
+              '<!@(<(pkg-config) --libs libpng)',
             ],
             'libraries': [
-              '<!@(<(pkg-config) --libs-only-l libpng)',
+              '<!@(<(pkg-config) --libs libpng)',
             ],
           },
         },
