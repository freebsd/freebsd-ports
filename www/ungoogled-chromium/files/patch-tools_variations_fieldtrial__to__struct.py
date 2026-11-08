--- tools/variations/fieldtrial_to_struct.py.orig	2026-10-31 12:09:36 UTC
+++ tools/variations/fieldtrial_to_struct.py
@@ -31,6 +31,8 @@ _platforms = [
   'linux',
   'mac',
   'windows',
+  'openbsd',
+  'freebsd',
 ]
 
 _form_factors = [
