--- native_client/src/shared/platform/platform.gyp.orig	2016-05-11 19:03:08 UTC
+++ native_client/src/shared/platform/platform.gyp
@@ -36,7 +36,7 @@
       'refcount_base.cc',
     ],
     'conditions': [
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="android" or OS=="freebsd"', {
         'platform_sources': [
           'linux/nacl_clock.c',
           'linux/nacl_host_dir.c',
