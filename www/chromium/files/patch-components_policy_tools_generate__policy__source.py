--- components/policy/tools/generate_policy_source.py.orig	2019-12-16 21:51:25 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -96,6 +96,7 @@ class PolicyDetails:
           'chrome.linux',
           'chrome.mac',
           'chrome.fuchsia',
+          'chrome.freebsd',
           'chrome.*',
           'chrome.win7',
       ]:
@@ -118,7 +119,7 @@ class PolicyDetails:
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux', 'fuchsia'])
+          self.platforms.extend(['win', 'mac', 'linux', 'fuchsia', 'freebsd'])
         elif platform_sub == 'win7':
           self.platforms.append('win')
         else:
