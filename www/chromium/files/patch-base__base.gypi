--- base/base.gypi.orig	2011-11-10 16:01:46.000000000 +0200
+++ base/base.gypi	2011-11-28 21:48:00.000000000 +0200
@@ -115,6 +115,7 @@
           'files/file_path_watcher_mac.cc',
           'files/file_path_watcher_stub.cc',
           'files/file_path_watcher_win.cc',
+          'files/file_path_watcher_freebsd.cc',
           'float_util.h',
           'format_macros.h',
           'global_descriptors_posix.cc',
@@ -216,6 +217,7 @@
           'process_posix.cc',
           'process_util.cc',
           'process_util.h',
+          'process_util_freebsd.cc',
           'process_util_linux.cc',
           'process_util_mac.mm',
           'process_util_openbsd.cc',
@@ -425,7 +427,7 @@
             'sources!' : [ 'message_pump_gtk.cc', ],
             'sources/' : [ [ 'include', 'message_pump_x.cc', ] ],
           }],
-          [ 'OS != "linux"', {
+          [ 'OS != "linux" and OS != "freebsd"', {
               'sources!': [
                 # Not automatically excluded by the *linux.cc rules.
                 'linux_util.cc',
@@ -498,6 +500,18 @@
               'files/file_path_watcher_stub.cc',
             ],
           }],
+          [ 'OS == "freebsd" and os_ver >= 801000', {
+            'sources!': [
+              'files/file_path_watcher_stub.cc',
+              'files/file_path_watcher_linux.cc',
+            ],
+          }],
+          [ 'OS == "freebsd" and os_ver < 801000', {
+            'sources!': [
+              'files/file_path_watcher_linux.cc',
+              'files/file_path_watcher_freebsd.cc',
+            ],
+          }],
           [ 'OS == "openbsd"', {
             'sources/': [
               ['include', '^base_paths_linux\\.cc$'],
@@ -600,6 +614,13 @@
           ],
         }],
         [ 'OS == "freebsd" or OS == "openbsd"', {
+          # XXX rene: maybe this chunk should go one day
+          'sources!': [
+             'file_util_linux.cc',
+             'process_linux.cc',
+             'process_util_linux.cc',
+             'files/file_path_watcher_linux.cc',
+          ],
           'include_dirs': [
             '/usr/local/include',
           ],
