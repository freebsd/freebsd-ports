--- base/base.gypi.orig	2011-03-21 21:48:13.059300970 +0200
+++ base/base.gypi	2011-03-21 21:49:30.340376078 +0200
@@ -157,6 +157,7 @@
           'process_posix.cc',
           'process_util.cc',
           'process_util.h',
+          'process_util_freebsd.cc',
           'process_util_linux.cc',
           'process_util_mac.mm',
           'process_util_posix.cc',
@@ -343,11 +344,9 @@
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
@@ -462,6 +461,12 @@
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
