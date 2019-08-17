--- Telegram/gyp/settings_linux.gypi.orig	2019-07-07 13:34:35 UTC
+++ Telegram/gyp/settings_linux.gypi
@@ -11,7 +11,6 @@
         'linux_common_flags': [
           '-pipe',
           '-Wall',
-          '-Werror',
           '-W',
           '-fPIC',
           '-Wno-unused-variable',
@@ -28,7 +27,7 @@
         ],
       },
       'conditions': [
-        [ '"<!(uname -m)" == "x86_64" or "<!(uname -m)" == "aarch64"', {
+        [ '"<!(uname -m)" == "amd64" or "<!(uname -m)" == "arm64"', {
           'defines': [
             'Q_OS_LINUX64',
           ],
@@ -63,7 +62,6 @@
       ],
       'defines': [
         '_REENTRANT',
-        'QT_STATICPLUGIN',
         'QT_PLUGIN',
       ],
       'cflags_c': [
@@ -76,9 +74,6 @@
         '-Wno-register',
       ],
       'make_global_settings': [
-        ['AR', '/usr/bin/gcc-ar'],
-        ['RANLIB', '/usr/bin/gcc-ranlib'],
-        ['NM', '/usr/bin/gcc-nm'],
       ],
       'configurations': {
         'Debug': {
