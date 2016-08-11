--- build/common.gypi.orig	2016-05-11 19:02:12 UTC
+++ build/common.gypi
@@ -112,7 +112,7 @@
 
           'conditions': [
             # Windows and Linux use Aura, but not Ash.
-            ['OS=="win" or OS=="linux"', {
+            ['OS=="win" or OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
               'use_aura%': 1,
             }],
 
@@ -254,13 +254,13 @@
           }],
 
           # Enable HiDPI on Mac OS, Windows and Linux (including Chrome OS).
-          ['OS=="mac" or OS=="win" or OS=="linux"', {
+          ['OS=="mac" or OS=="win" or OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
             'enable_hidpi%': 1,
           }],
 
           # Enable Top Chrome Material Design on Chrome OS, Windows, and Linux,
           # and Mac.
-          ['chromeos==1 or OS=="win" or OS=="linux" or OS=="mac"', {
+          ['chromeos==1 or OS=="win" or OS=="linux" or OS=="mac" or OS=="freebsd" or OS=="openbsd"', {
             'enable_topchrome_md%': 1,
           }],
 
@@ -733,6 +733,12 @@
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
@@ -778,7 +784,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -881,7 +887,7 @@
 
         # Use GPU accelerated cross process image transport by default
         # on linux builds with the Aura window manager
-        ['use_aura==1 and OS=="linux"', {
+        ['use_aura==1 and (OS=="linux" or OS=="freebsd" or OS=="openbsd")', {
           'ui_compositor_image_transport%': 1,
         }, {
           'ui_compositor_image_transport%': 0,
@@ -1003,7 +1009,7 @@
         }, {
           'use_openmax_dl_fft%': 0,
         }],
-        ['OS=="win" or OS=="linux"', {
+        ['OS=="win" or OS=="linux" or OS=="freebsd"', {
           'enable_mdns%' : 1,
         }],
 
@@ -1300,6 +1306,10 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    # XXX(rene) More options, keep them?
+    'os_ver%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -4715,6 +4725,13 @@
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
