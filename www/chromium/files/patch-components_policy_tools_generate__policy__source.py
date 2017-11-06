--- components/policy/tools/generate_policy_source.py.orig	2017-09-07 05:49:44.475708000 +0200
+++ components/policy/tools/generate_policy_source.py	2017-09-07 06:03:36.269823000 +0200
@@ -90,7 +90,7 @@
       if platform not in ['chrome_frame', 'chrome_os',
                           'android', 'webview_android',
                           'chrome.win', 'chrome.linux', 'chrome.mac',
-                          'chrome.*']:
+                          'chrome.bsd', 'chrome.*']:
         raise RuntimeError('Platform "%s" is not supported' % platform)
 
       split_result = version_range.split('-')
@@ -108,7 +108,7 @@
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux'])
+          self.platforms.extend(['win', 'mac', 'linux', 'bsd'])
         else:
           self.platforms.append(platform_sub)
       else:
