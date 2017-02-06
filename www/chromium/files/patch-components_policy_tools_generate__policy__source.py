--- components/policy/tools/generate_policy_source.py.orig	2017-01-26 00:49:12 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -102,7 +102,7 @@ class PolicyDetails:
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux'])
+          self.platforms.extend(['win', 'mac', 'linux', 'bsd'])
         else:
           self.platforms.append(platform_sub)
       else:
