--- Telegram/gyp/settings_linux.gypi.orig	2017-09-05 17:38:38 UTC
+++ Telegram/gyp/settings_linux.gypi
@@ -25,7 +25,6 @@
           '-pipe',
           '-g',
           '-Wall',
-          '-Werror',
           '-W',
           '-fPIC',
           '-Wno-unused-variable',
@@ -61,7 +60,6 @@
       ],
       'defines': [
         '_REENTRANT',
-        'QT_STATICPLUGIN',
         'QT_PLUGIN',
       ],
       'cflags_c': [
