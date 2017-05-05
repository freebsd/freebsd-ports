--- src/3rdparty/chromium/build/common.gypi.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/build/common.gypi
@@ -4781,6 +4781,13 @@
         'ldflags': [
           '-Wl,--no-keep-memory',
         ],
+        'ldflags!': [
+          '-ldl',
+          '-pie',
+        ],
+        'libraries!': [
+          '-ldl',
+        ],
       },
     }],
     # Android-specific options; note that most are set above with Linux.
