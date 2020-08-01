--- components/policy/tools/generate_policy_source.py.orig	2020-07-07 21:58:15 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -37,8 +37,9 @@ PLATFORM_STRINGS = {
     'ios': ['ios'],
     'chrome.win': ['win'],
     'chrome.linux': ['linux'],
+    'chrome.freebsd': ['freebsd'],
     'chrome.mac': ['mac'],
-    'chrome.*': ['win', 'mac', 'linux'],
+    'chrome.*': ['win', 'mac', 'linux', 'freebsd'],
     'chrome.win7': ['win']
 }
 
