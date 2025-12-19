--- src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py
@@ -41,6 +41,8 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'openbsd',
+    'freebsd',
 ]
 
 _form_factors = [
