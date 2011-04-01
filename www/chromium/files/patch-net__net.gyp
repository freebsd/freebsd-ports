--- net/net.gyp.orig	2011-03-20 22:02:04.177736414 +0200
+++ net/net.gyp	2011-03-20 22:02:04.391765571 +0200
@@ -137,8 +137,8 @@
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
@@ -242,7 +242,7 @@
             'dependencies': [
               '../build/linux/system.gyp:gconf',
               '../build/linux/system.gyp:gdk',
-              '../build/linux/system.gyp:libresolv',
+              #'../build/linux/system.gyp:libresolv',
             ],
             'conditions': [
               ['use_openssl==1', {
@@ -548,8 +548,8 @@
         'proxy/proxy_config_service.h',
         'proxy/proxy_config_service_fixed.cc',
         'proxy/proxy_config_service_fixed.h',
-        'proxy/proxy_config_service_linux.cc',
-        'proxy/proxy_config_service_linux.h',
+        #'proxy/proxy_config_service_linux.cc',
+        #'proxy/proxy_config_service_linux.h',
         'proxy/proxy_config_service_mac.cc',
         'proxy/proxy_config_service_mac.h',
         'proxy/proxy_config_service_win.cc',
@@ -1029,7 +1029,7 @@
             ],
           }
         ],
-        [ 'OS == "linux"', {
+        [ 'OS == "linux" or OS=="freebsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
@@ -1194,7 +1194,7 @@
             }],
           ],
         }],
-        ['OS == "linux"', {
+        ['OS == "linux" or OS=="freebsd"', {
           'conditions': [
             ['linux_use_tcmalloc==1', {
               'dependencies': [
