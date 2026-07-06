--- build/modules/unified/modulemap_config.py.orig	2026-07-01 06:24:19 UTC
+++ build/modules/unified/modulemap_config.py
@@ -57,7 +57,7 @@ class AllowedHeader(Header):
 
 
 def headers(os):
-  is_linux = os == 'linux'
+  is_linux = os == 'linux' or os == 'openbsd' or os == 'freebsd'
   is_android = os == 'android'
   is_ios = os == 'ios'
   is_mac = os == 'mac'
