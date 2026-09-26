--- build/modules/unified/modulemap_config.py.orig	2026-09-25 15:26:43 UTC
+++ build/modules/unified/modulemap_config.py
@@ -62,7 +62,7 @@ class AllowedHeader(Header):
 
 
 def headers(os):
-    is_linux = os == 'linux'
+    is_linux = os == 'linux' or os == 'openbsd' or os == 'freebsd'
     is_android = os == 'android'
     is_ios = os == 'ios'
     is_mac = os == 'mac'
