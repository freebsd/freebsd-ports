--- ./native_client/src/shared/platform/platform.gyp.orig	2010-12-16 02:12:14.000000000 +0100
+++ ./native_client/src/shared/platform/platform.gyp	2010-12-20 20:15:08.000000000 +0100
@@ -60,7 +60,7 @@
       'time.h',
     ],
     'conditions': [
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="freebsd"', {
         'platform_sources': [
           'linux/condition_variable.cc',
           'linux/lock.cc',
