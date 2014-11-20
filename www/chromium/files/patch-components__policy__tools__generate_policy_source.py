--- components/policy/tools/generate_policy_source.py.orig	2014-10-10 08:54:14 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -73,7 +73,7 @@
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux'])
+          self.platforms.extend(['win', 'mac', 'linux', 'freebsd'])
         else:
           self.platforms.append(platform_sub)
       else:
