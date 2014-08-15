--- ./build/common.gypi.orig	2014-08-12 21:02:52.000000000 +0200
+++ ./build/common.gypi	2014-08-13 09:56:56.000000000 +0200
@@ -101,7 +101,7 @@
             #
             # TODO(erg): Merge this into the previous block once compiling with
             # aura safely implies including ash capabilities.
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'use_aura%': 1,
             }],
 
@@ -622,7 +622,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -896,7 +896,7 @@
         # except when building Android WebView.
         # TODO(jshin): Handle 'use_system_icu' on Linux (Chromium).
         # Set the data reduction proxy origin for Android Webview.
-        ['android_webview_build==0', {
+        ['android_webview_build==0 and OS!="freebsd" and OS!="openbsd"', {
           'icu_use_data_file_flag%' : 1,
           'spdy_proxy_auth_origin%': '',
           'data_reduction_proxy_probe_url%': '',
@@ -1106,6 +1106,9 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    'os_ver%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -3960,6 +3963,13 @@
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
