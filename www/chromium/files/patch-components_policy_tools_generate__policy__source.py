--- components/policy/tools/generate_policy_source.py.orig	2021-09-24 04:26:04 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -47,8 +47,9 @@ PLATFORM_STRINGS = {
     'ios': ['ios'],
     'chrome.win': ['win'],
     'chrome.linux': ['linux'],
+    'chrome.freebsd': ['freebsd'],
     'chrome.mac': ['mac'],
-    'chrome.*': ['win', 'mac', 'linux', 'fuchsia'],
+    'chrome.*': ['win', 'mac', 'linux', 'fuchsia', 'freebsd'],
     'chrome.win7': ['win'],
 }
 
