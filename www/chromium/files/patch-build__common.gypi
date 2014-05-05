--- ./build/common.gypi.orig	2014-04-24 22:36:09.000000000 +0200
+++ ./build/common.gypi	2014-04-24 23:23:42.000000000 +0200
@@ -565,7 +565,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -1002,6 +1002,10 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    'os_ver%': 0,
+    'prefix_dir%': '/usr',
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -1322,7 +1326,7 @@
           # TODO(jungshik): Turn this on on Android.
           # For ChromeOS, this should be turned on in chromeos-chrome.ebuild
           # file as well by adding icu_use_data_file_flag=1 to BUILD_DEFINES.
-          ['OS!="android"', {
+          ['OS!="android" and os_bsd!=1', {
             'icu_use_data_file_flag%': 1,
           }],
         ],
@@ -3701,6 +3705,13 @@
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
