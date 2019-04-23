--- Telegram/gyp/settings_linux.gypi.orig	2019-04-13 06:46:58 UTC
+++ Telegram/gyp/settings_linux.gypi
@@ -11,7 +11,6 @@
         'linux_common_flags': [
           '-pipe',
           '-Wall',
-          '-Werror',
           '-W',
           '-fPIC',
           '-Wno-unused-variable',
@@ -26,7 +25,7 @@
         ],
       },
       'conditions': [
-        [ '"<!(uname -m)" == "x86_64" or "<!(uname -m)" == "aarch64"', {
+        [ '"<!(uname -m)" == "amd64" or "<!(uname -m)" == "arm64"', {
           'defines': [
             'Q_OS_LINUX64',
           ],
@@ -61,7 +60,6 @@
       ],
       'defines': [
         '_REENTRANT',
-        'QT_STATICPLUGIN',
         'QT_PLUGIN',
       ],
       'cflags_c': [
@@ -74,9 +72,6 @@
         '-Wno-register',
       ],
       'make_global_settings': [
-        ['AR', '/usr/bin/gcc-ar'],
-        ['RANLIB', '/usr/bin/gcc-ranlib'],
-        ['NM', '/usr/bin/gcc-nm'],
       ],
       'configurations': {
         'Debug': {
