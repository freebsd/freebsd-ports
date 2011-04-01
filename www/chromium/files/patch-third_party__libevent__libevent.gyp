--- ./third_party/libevent/libevent.gyp.orig	2010-12-16 02:11:36.000000000 +0100
+++ ./third_party/libevent/libevent.gyp	2010-12-20 20:15:08.000000000 +0100
@@ -45,15 +45,18 @@
               'link_settings': {
                 'libraries': [
                   # We need rt for clock_gettime().
-                  # TODO(port) Maybe on FreeBSD as well?
                   '-lrt',
                 ],
               },
             }],
-            [ 'OS == "mac" or OS == "freebsd" or OS == "openbsd" or OS == "solaris"', {
+            [ 'OS == "mac" or OS == "openbsd" or OS == "solaris"', {
               'sources': [ 'kqueue.c' ],
               'include_dirs': [ 'mac' ]
             }],
+            [ 'OS == "freebsd"', {
+              'sources': [ 'kqueue.c' ],
+              'include_dirs': [ 'freebsd' ]
+            }],
           ],
         },
       ],
