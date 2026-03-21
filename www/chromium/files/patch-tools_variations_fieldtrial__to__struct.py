--- tools/variations/fieldtrial_to_struct.py.orig	2026-03-13 06:02:14 UTC
+++ tools/variations/fieldtrial_to_struct.py
@@ -33,6 +33,8 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'openbsd',
+    'freebsd',
 ]
 
 _form_factors = [
