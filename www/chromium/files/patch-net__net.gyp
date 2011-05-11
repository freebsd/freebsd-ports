--- net/net.gyp.orig	2011-04-26 11:01:16.000000000 +0300
+++ net/net.gyp	2011-05-03 21:16:49.479149025 +0300
@@ -138,8 +138,8 @@
         'base/network_change_notifier_linux.h',
         'base/network_change_notifier_mac.cc',
         'base/network_change_notifier_mac.h',
-        'base/network_change_notifier_netlink_linux.cc',
-        'base/network_change_notifier_netlink_linux.h',
+        #'base/network_change_notifier_netlink_linux.cc',
+        #'base/network_change_notifier_netlink_linux.h',
         'base/network_change_notifier_win.cc',
         'base/network_change_notifier_win.h',
         'base/network_config_watcher_mac.cc',
@@ -245,7 +245,7 @@
             'dependencies': [
               '../build/linux/system.gyp:gconf',
               '../build/linux/system.gyp:gdk',
-              '../build/linux/system.gyp:libresolv',
+              #'../build/linux/system.gyp:libresolv',
             ],
             'conditions': [
               ['use_openssl==1', {
@@ -1023,7 +1023,7 @@
             ],
           }
         ],
-        [ 'OS == "linux"', {
+        [ 'OS == "linux" or OS=="freebsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -1196,7 +1196,7 @@
             }],
           ],
         }],
-        ['OS == "linux"', {
+        ['OS == "linux" or OS=="freebsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
