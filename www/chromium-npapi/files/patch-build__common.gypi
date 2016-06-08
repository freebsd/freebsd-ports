--- ./build/common.gypi.orig	2014-04-30 22:43:21.000000000 +0200
+++ ./build/common.gypi	2014-05-04 14:43:03.000000000 +0200
@@ -615,7 +615,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -878,7 +878,7 @@
         # By default, use ICU data file (icudtl.dat) on all platforms
         # except when building Android WebView.
         # TODO(jshin): Handle 'use_system_icu' on Linux (Chromium).
-        ['android_webview_build==0', {
+        ['android_webview_build==0 and OS!="freebsd" and OS!="openbsd"', {
           'icu_use_data_file_flag%' : 1,
         }, {
           'icu_use_data_file_flag%' : 0,
@@ -1076,6 +1076,9 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    'os_ver%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -3894,6 +3897,13 @@
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
