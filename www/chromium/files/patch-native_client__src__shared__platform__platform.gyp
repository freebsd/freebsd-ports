--- ./native_client/src/shared/platform/platform.gyp.orig	2014-08-20 21:03:23.000000000 +0200
+++ ./native_client/src/shared/platform/platform.gyp	2014-08-22 15:06:26.000000000 +0200
@@ -36,7 +36,7 @@
       'refcount_base.cc',
     ],
     'conditions': [
-      ['OS=="linux" or OS=="android"', {
+      ['OS=="linux" or OS=="android" or OS=="freebsd"', {
         'platform_sources': [
           'linux/nacl_clock.c',
           'linux/nacl_host_dir.c',
