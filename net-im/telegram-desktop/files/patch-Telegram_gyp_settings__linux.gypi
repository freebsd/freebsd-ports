--- Telegram/gyp/settings_linux.gypi.orig	2018-01-03 10:46:01 UTC
+++ Telegram/gyp/settings_linux.gypi
@@ -11,7 +11,6 @@
         'linux_common_flags': [
           '-pipe',
           '-Wall',
-          '-Werror',
           '-W',
           '-fPIC',
           '-Wno-unused-variable',
@@ -25,7 +24,7 @@
         ],
       },
       'conditions': [
-        [ '"<!(uname -m)" == "x86_64" or "<!(uname -m)" == "aarch64"', {
+        [ '"<!(uname -m)" == "amd64" or "<!(uname -m)" == "arm64"', {
           'defines': [
             'Q_OS_LINUX64',
           ],
@@ -47,7 +46,6 @@
       ],
       'defines': [
         '_REENTRANT',
-        'QT_STATICPLUGIN',
         'QT_PLUGIN',
       ],
       'cflags_c': [
