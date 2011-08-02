--- net/net.gyp.orig	2011-06-24 11:30:36.000000000 +0300
+++ net/net.gyp	2011-06-28 20:55:27.155810165 +0300
@@ -149,8 +149,8 @@
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
@@ -731,7 +731,7 @@
               '../build/linux/system.gyp:gconf',
               '../build/linux/system.gyp:gdk',
               '../build/linux/system.gyp:gio',
-              '../build/linux/system.gyp:libresolv',
+              #'../build/linux/system.gyp:libresolv',
             ],
             'conditions': [
               ['use_openssl==1', {
