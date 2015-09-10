--- net/net.gyp.orig	2015-05-13 18:35:47.000000000 -0400
+++ net/net.gyp         2015-05-20 16:09:23.255544000 -0400
@@ -146,7 +146,7 @@
         '<@(net_test_sources)',
       ],
       'conditions': [
-        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android"', {
+        ['os_posix == 1 and OS != "mac" and OS != "ios" and OS != "android" and os_bsd != 1', {
           'dependencies': [
             'epoll_quic_tools',
             'epoll_server',
@@ -659,6 +659,11 @@
               'test/cert_test_util_nss.cc',
             ],
         }],
+        [ 'os_bsd == 1', {
+          'sources!': [
+            'base/address_tracker_linux_unittest.cc',
+          ],
+        }],
       ],
       # TODO(jschuh): crbug.com/167187 fix size_t to int truncations.
       'msvs_disabled_warnings': [4267, ],
