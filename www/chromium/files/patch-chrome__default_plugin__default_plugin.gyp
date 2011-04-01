--- ./chrome/default_plugin/default_plugin.gyp.orig	2010-12-16 02:12:13.000000000 +0100
+++ ./chrome/default_plugin/default_plugin.gyp	2010-12-20 20:15:08.000000000 +0100
@@ -53,7 +53,7 @@
               'plugin_install_job_monitor.h',
             ],
          }],
-         ['OS=="linux"', {
+         ['OS=="linux" or OS=="freebsd"', {
             'dependencies': [
               '<(DEPTH)/build/linux/system.gyp:gtk',
             ],
