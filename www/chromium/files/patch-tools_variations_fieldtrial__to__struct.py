--- tools/variations/fieldtrial_to_struct.py.orig	2026-09-25 15:26:43 UTC
+++ tools/variations/fieldtrial_to_struct.py
@@ -31,6 +31,8 @@ _platforms = [
   'linux',
   'mac',
   'windows',
+  'openbsd',
+  'freebsd',
 ]
 
 _form_factors = [
