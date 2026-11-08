--- build/modules/unified/modulemap_config.py.orig	2026-10-31 12:09:36 UTC
+++ build/modules/unified/modulemap_config.py
@@ -62,7 +62,7 @@ class AllowedHeader(Header):
 
 
 def headers(os):
-    is_linux = os == 'linux'
+    is_linux = os == 'linux' or os == 'openbsd' or os == 'freebsd'
     is_android = os == 'android'
     is_ios = os == 'ios'
     is_mac = os == 'mac'
