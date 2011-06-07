--- base/base.gypi.orig	2011-05-06 12:03:16.000000000 +0300
+++ base/base.gypi	2011-06-05 19:27:52.717164750 +0300
@@ -190,6 +190,7 @@
           'process_posix.cc',
           'process_util.cc',
           'process_util.h',
+          'process_util_freebsd.cc',
           'process_util_linux.cc',
           'process_util_mac.mm',
           'process_util_posix.cc',
@@ -363,11 +364,9 @@
                 'message_pump_glib_x.cc',
               ],
           }],
-          [ 'OS != "linux"', {
+          [ 'OS != "linux" and OS != "freebsd"', {
               'sources!': [
                 # Not automatically excluded by the *linux.cc rules.
-                'gtk_util.cc',
-                'gtk_util.h',
                 'linux_util.cc',
               ],
             },
@@ -408,10 +407,10 @@
           },],
           ['OS=="freebsd" or OS=="openbsd"', {
             'sources!': [
-              'base/files/file_path_watcher_linux.cc',
+              'files/file_path_watcher_linux.cc',
             ],
             'sources': [
-              'base/files/file_path_watcher_stub.cc',
+              'files/file_path_watcher_stub.cc',
             ],
           }],
         ],
@@ -481,6 +480,12 @@
             ],
         }],
         [ 'OS == "freebsd" or OS == "openbsd"', {
+          # XXX rene: maybe this chunk should go one day
+          'sources!': [
+             'file_util_linux.cc',
+             'process_linux.cc',
+             'process_util_linux.cc',
+          ],
           'link_settings': {
             'libraries': [
               '-L/usr/local/lib -lexecinfo',
