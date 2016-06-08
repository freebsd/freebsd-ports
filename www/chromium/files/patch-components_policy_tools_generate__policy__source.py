--- components/policy/tools/generate_policy_source.py.orig	2016-05-11 19:02:19 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -98,7 +98,7 @@ class PolicyDetails:
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux'])
+          self.platforms.extend(['win', 'mac', 'linux', 'freebsd'])
         else:
           self.platforms.append(platform_sub)
       else:
