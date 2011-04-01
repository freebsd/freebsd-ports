--- ./native_client/src/trusted/debug_stub/debug_stub.gyp.orig	2010-12-16 02:12:15.000000000 +0100
+++ ./native_client/src/trusted/debug_stub/debug_stub.gyp	2010-12-20 20:15:08.000000000 +0100
@@ -16,7 +16,7 @@
       'transport_common.cc',
     ],
     'conditions': [
-      ['OS=="linux" or OS=="mac"', {
+      ['OS=="linux" or OS=="freebsd" or OS=="mac"', {
         'platform_sources': [
           'posix/debug_stub_posix.cc',
           'posix/mutex_impl.cc',
@@ -40,7 +40,7 @@
       'target_base': 'none',
     },
     'target_conditions': [
-      ['OS=="linux" or OS=="mac"', {
+      ['OS=="linux" or OS=="freebsd" or OS=="mac"', {
         'cflags': [
           '-Wno-long-long',
         ],
