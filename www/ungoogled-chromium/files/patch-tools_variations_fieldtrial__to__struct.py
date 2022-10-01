--- tools/variations/fieldtrial_to_struct.py.orig	2022-10-01 07:40:07 UTC
+++ tools/variations/fieldtrial_to_struct.py
@@ -41,6 +41,8 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'openbsd',
+    'freebsd',
 ]
 
 _form_factors = [
