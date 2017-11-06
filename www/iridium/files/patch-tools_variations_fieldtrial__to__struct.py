--- tools/variations/fieldtrial_to_struct.py.orig	2017-04-19 19:06:54 UTC
+++ tools/variations/fieldtrial_to_struct.py
@@ -116,7 +116,7 @@ def main(arguments):
   if not opts.platform:
     parser.error('You must specify a --platform.')
 
-  supported_platforms = ['android', 'chromeos', 'ios', 'linux', 'mac', 'win']
+  supported_platforms = ['android', 'chromeos', 'ios', 'linux', 'mac', 'win', 'bsd']
   if opts.platform not in supported_platforms:
     parser.error('\'%s\' is an unknown platform. Supported platforms: %s' %
         (opts.platform, supported_platforms))
