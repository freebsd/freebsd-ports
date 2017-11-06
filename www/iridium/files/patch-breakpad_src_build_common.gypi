--- breakpad/src/build/common.gypi.orig	2017-04-19 19:07:40 UTC
+++ breakpad/src/build/common.gypi
@@ -813,15 +813,6 @@
         ],
       },
     }],
-    # FreeBSD-specific options; note that most FreeBSD options are set above,
-    # with Linux.
-    ['OS=="freebsd"', {
-      'target_defaults': {
-        'ldflags': [
-          '-Wl,--no-keep-memory',
-        ],
-      },
-    }],
     ['OS=="solaris"', {
       'cflags!': ['-fvisibility=hidden'],
       'cflags_cc!': ['-fvisibility-inlines-hidden'],
