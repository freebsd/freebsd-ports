--- chrome/common/extensions/api/api.gyp.orig	2012-07-01 22:41:26.000000000 +0300
+++ chrome/common/extensions/api/api.gyp	2012-07-01 22:57:38.000000000 +0300
@@ -33,7 +33,7 @@
           'experimental.dns.idl',
           'experimental.serial.idl',
           'experimental.socket.idl',
-          'experimental.usb.idl',
+#          'experimental.usb.idl',
         ],
         'cc_dir': 'chrome/common/extensions/api',
         'root_namespace': 'extensions::api',
