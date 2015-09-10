--- build/common.gypi.orig	2015-07-15 16:29:56.000000000 -0400
+++ build/common.gypi	2015-07-22 18:47:32.413623000 -0400
@@ -97,7 +97,7 @@
 
           'conditions': [
             # ChromeOS and Windows use Aura and Ash.
-            ['chromeos==1 or OS=="win" or OS=="linux"', {
+            ['chromeos==1 or OS=="win" or OS=="linux" or OS=="freebsd"', {
               'use_ash%': 1,
               'use_aura%': 1,
             }],
@@ -676,7 +676,7 @@
       # Whether the entire browser uses toolkit-views on Mac instead of Cocoa.
       'mac_views_browser%': 0,
 
-      # By default, use ICU data file (icudtl.dat).
+      # By default, use ICU data file (icudtl.dat)
       'icu_use_data_file_flag%': 1,
 
       # Turn on JNI generation optimizations by default.
@@ -697,6 +697,12 @@
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
@@ -735,7 +741,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -986,7 +992,7 @@
         }, {
           'use_openmax_dl_fft%': 0,
         }],
-        ['OS=="win" or OS=="linux"', {
+        ['OS=="win" or OS=="linux" or OS=="freebsd"', {
             'enable_mdns%' : 1,
         }],
 
@@ -1248,6 +1254,10 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    # XXX(rene) More options, keep them?
+    'os_ver%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -4631,6 +4641,13 @@
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
