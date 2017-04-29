--- components/policy/tools/generate_policy_source.py.orig	2017-04-19 19:06:33 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -103,7 +103,7 @@ class PolicyDetails:
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux'])
+          self.platforms.extend(['win', 'mac', 'linux', 'bsd'])
         else:
           self.platforms.append(platform_sub)
       else:
