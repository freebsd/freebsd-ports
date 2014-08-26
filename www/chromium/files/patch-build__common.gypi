--- ./build/common.gypi.orig	2014-08-20 21:02:29.000000000 +0200
+++ ./build/common.gypi	2014-08-22 15:06:24.000000000 +0200
@@ -87,7 +87,7 @@
 
           'conditions': [
             # ChromeOS and Windows use Aura and Ash.
-            ['chromeos==1 or OS=="win" or OS=="linux"', {
+            ['chromeos==1 or OS=="win" or OS=="linux" or OS=="freebsd"', {
               'use_ash%': 1,
               'use_aura%': 1,
             }],
@@ -645,7 +645,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -926,7 +926,7 @@
         # except when building Android WebView.
         # TODO(jshin): Handle 'use_system_icu' on Linux (Chromium).
         # Set the data reduction proxy origin for Android Webview.
-        ['android_webview_build==0', {
+        ['android_webview_build==0 and OS!="freebsd" and OS!="openbsd"', {
           'icu_use_data_file_flag%' : 1,
           'spdy_proxy_auth_origin%': '',
           'data_reduction_proxy_probe_url%': '',
@@ -1153,6 +1153,10 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    # XXX(rene) More options, keep them?
+    'os_ver%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -4150,6 +4154,13 @@
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
