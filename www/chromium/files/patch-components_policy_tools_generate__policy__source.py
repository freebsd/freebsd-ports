--- components/policy/tools/generate_policy_source.py.orig	2016-08-03 22:02:16.000000000 +0300
+++ components/policy/tools/generate_policy_source.py	2016-09-20 17:13:04.971596000 +0300
@@ -102,7 +102,7 @@
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux'])
+          self.platforms.extend(['win', 'mac', 'linux', 'bsd'])
         else:
           self.platforms.append(platform_sub)
       else:
