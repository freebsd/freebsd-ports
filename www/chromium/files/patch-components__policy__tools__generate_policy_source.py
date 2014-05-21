--- ./components/policy/tools/generate_policy_source.py.orig	2014-04-30 22:43:03.000000000 +0200
+++ ./components/policy/tools/generate_policy_source.py	2014-05-04 14:38:46.000000000 +0200
@@ -64,7 +64,7 @@
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux'])
+          self.platforms.extend(['win', 'mac', 'linux', 'freebsd'])
         else:
           self.platforms.append(platform_sub)
       else:
