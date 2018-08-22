--- Telegram/gyp/settings_linux.gypi.orig	2018-08-04 18:53:40 UTC
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
@@ -60,7 +59,6 @@
       ],
       'defines': [
         '_REENTRANT',
-        'QT_STATICPLUGIN',
         'QT_PLUGIN',
       ],
       'cflags_c': [
@@ -73,9 +71,6 @@
         '-Wno-register',
       ],
       'make_global_settings': [
-        ['AR', '/usr/bin/gcc-ar'],
-        ['RANLIB', '/usr/bin/gcc-ranlib'],
-        ['NM', '/usr/bin/gcc-nm'],
       ],
       'configurations': {
         'Debug': {
