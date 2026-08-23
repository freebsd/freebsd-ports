--- cargo-crates/v8-150.4.0/build/modules/unified/modulemap_config.py.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-150.4.0/build/modules/unified/modulemap_config.py
@@ -57,7 +57,7 @@ def headers(os):
 
 
 def headers(os):
-  is_linux = os == 'linux'
+  is_linux = os == 'linux' or os == 'openbsd' or os == 'freebsd'
   is_android = os == 'android'
   is_ios = os == 'ios'
   is_mac = os == 'mac'
