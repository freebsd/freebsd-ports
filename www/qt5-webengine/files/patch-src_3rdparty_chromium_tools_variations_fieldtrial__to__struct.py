--- src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py
@@ -30,6 +30,7 @@ _platforms = [
   'linux',
   'mac',
   'windows',
+  'bsd',
 ]
 
 # Convert a platform argument to the matching Platform enum value in
