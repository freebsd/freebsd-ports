--- components/policy/tools/generate_policy_source.py.orig	2017-12-15 02:04:15.000000000 +0100
+++ components/policy/tools/generate_policy_source.py	2017-12-24 12:04:08.751317000 +0100
@@ -91,7 +91,7 @@
         raise RuntimeError('is_device_only is only allowed for Chrome OS: "%s"'
                            % p)
       if platform not in ['chrome_frame', 'chrome_os',
-                          'android', 'webview_android',
+                          'android', 'webview_android', 'chrome.bsd',
                           'chrome.win', 'chrome.linux', 'chrome.mac',
                           'chrome.fuchsia', 'chrome.*']:
         raise RuntimeError('Platform "%s" is not supported' % platform)
@@ -111,7 +111,7 @@
       if platform.startswith('chrome.'):
         platform_sub = platform[7:]
         if platform_sub == '*':
-          self.platforms.extend(['win', 'mac', 'linux', 'fuchsia'])
+          self.platforms.extend(['win', 'mac', 'linux', 'fuchsia', 'bsd'])
         else:
           self.platforms.append(platform_sub)
       else:
