--- src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py
@@ -24,6 +24,7 @@ finally:
 _platforms = [
   'android',
   'android_webview',
+  'freebsd',
   'chromeos',
   'fuchsia',
   'ios',
