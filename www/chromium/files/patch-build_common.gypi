--- build/common.gypi.orig	2016-07-22 00:06:49.000000000 -0400
+++ build/common.gypi	2016-08-03 11:18:18.437811000 -0400
@@ -726,6 +726,12 @@
           'os_bsd%': 0,
         }],
 
+        ['OS=="freebsd" or OS=="openbsd"', {
+            'icu_use_data_file_flag%': 0,
+        }, {
+            'icu_use_data_file_flag%': 1,
+        }],
+
         # NSS usage.
         ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris")', {
           'use_nss_certs%': 1,
@@ -1303,6 +1309,10 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    # XXX(rene) More options, keep them?
+    'os_ver%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -4709,6 +4719,13 @@
         'ldflags': [
           '-Wl,--no-keep-memory',
         ],
+        'ldflags!': [
+          '-ldl',
+          '-pie'
+        ],
+        'libraries!': [
+          '-ldl',
+        ],
       },
     }],
     # Android-specific options; note that most are set above with Linux.
