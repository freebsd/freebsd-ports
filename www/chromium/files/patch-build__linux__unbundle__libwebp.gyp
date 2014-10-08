--- build/linux/unbundle/libwebp.gyp.orig	2014-10-02 17:18:52 UTC
+++ build/linux/unbundle/libwebp.gyp
@@ -14,13 +14,7 @@
       },
       'link_settings': {
         'libraries': [
-          # Check for presence of webpdemux library, use it if present.
-          '<!(python <(DEPTH)/tools/compile_test/compile_test.py '
-          '--code "int main() { return 0; }" '
-          '--run-linker '
-          '--on-success "-lwebp -lwebpdemux" '
-          '--on-failure "-lwebp" '
-          '-- -lwebpdemux)',
+          '-lwebp -lwebpdemux',
         ],
       },
     }
