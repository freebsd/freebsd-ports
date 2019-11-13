--- components/policy/tools/generate_policy_source.py.orig	2019-10-21 19:06:30 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -92,6 +92,7 @@ class PolicyDetails:
           'chrome.linux',
           'chrome.mac',
           'chrome.fuchsia',
+          'chrome.freebsd',
           'chrome.*',
           'chrome.win7',
       ]:
@@ -114,7 +115,7 @@ class PolicyDetails:
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux', 'fuchsia'])
+          self.platforms.extend(['win', 'mac', 'linux', 'fuchsia', 'freebsd'])
         elif platform_sub == 'win7':
           self.platforms.append('win')
         else:
