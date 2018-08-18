--- tools/variations/fieldtrial_to_struct.py.orig	2017-12-15 02:04:51.000000000 +0100
+++ tools/variations/fieldtrial_to_struct.py	2017-12-24 19:54:09.044002000 +0100
@@ -117,7 +117,7 @@
     parser.error('You must specify a --platform.')
 
   supported_platforms = ['android', 'chromeos', 'fuchsia', 'ios', 'linux',
-                         'mac', 'win']
+                         'mac', 'win', 'bsd']
   if opts.platform not in supported_platforms:
     parser.error('\'%s\' is an unknown platform. Supported platforms: %s' %
         (opts.platform, supported_platforms))
