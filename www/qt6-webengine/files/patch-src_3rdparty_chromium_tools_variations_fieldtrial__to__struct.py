--- src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py
@@ -41,6 +41,8 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'openbsd',
+    'freebsd',
 ]
 
 _form_factors = [
