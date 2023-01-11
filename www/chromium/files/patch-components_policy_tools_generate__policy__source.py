--- components/policy/tools/generate_policy_source.py.orig	2023-01-11 09:17:16 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -49,9 +49,9 @@ PLATFORM_STRINGS = {
     'ios': ['ios'],
     'fuchsia': ['fuchsia'],
     'chrome.win': ['win'],
-    'chrome.linux': ['linux'],
+    'chrome.linux': ['linux', 'openbsd', 'freebsd'],
     'chrome.mac': ['mac'],
-    'chrome.*': ['win', 'mac', 'linux'],
+    'chrome.*': ['win', 'mac', 'linux', 'openbsd', 'freebsd'],
     'chrome.win7': ['win'],
 }
 
