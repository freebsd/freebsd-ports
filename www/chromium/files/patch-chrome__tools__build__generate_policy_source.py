--- chrome/tools/build/generate_policy_source.py.orig	2013-09-24 21:55:28.000000000 +0300
+++ chrome/tools/build/generate_policy_source.py	2013-09-24 21:56:43.000000000 +0300
@@ -67,7 +67,7 @@
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux'])
+          self.platforms.extend(['win', 'mac', 'linux', 'freebsd'])
         else:
           self.platforms.append(platform_sub)
       else:
