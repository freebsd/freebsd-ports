--- tools/variations/fieldtrial_to_struct.py.orig	2025-05-07 06:48:23 UTC
+++ tools/variations/fieldtrial_to_struct.py
@@ -41,6 +41,8 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'openbsd',
+    'freebsd',
 ]
 
 _form_factors = [
