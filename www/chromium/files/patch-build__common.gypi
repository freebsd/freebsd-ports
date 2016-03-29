--- build/common.gypi.orig	2015-09-01 16:10:41.000000000 -0400
+++ build/common.gypi	2015-09-03 09:38:09.528529000 -0400
@@ -105,7 +105,7 @@
 
           'conditions': [
             # Windows and Linux (including Chrome OS) use Aura and Ash.
-            ['OS=="win" or OS=="linux"', {
+            ['OS=="win" or OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
               'use_ash%': 1,
               'use_aura%': 1,
             }],
@@ -729,6 +729,12 @@
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
@@ -767,7 +773,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -1011,7 +1011,7 @@
         }, {
           'use_openmax_dl_fft%': 0,
         }],
-        ['OS=="win" or OS=="linux"', {
+        ['OS=="win" or OS=="linux" or OS=="freebsd"', {
           'enable_mdns%' : 1,
         }],
 
@@ -1263,6 +1269,10 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    # XXX(rene) More options, keep them?
+    'os_ver%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -4698,6 +4708,13 @@
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
