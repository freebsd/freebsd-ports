--- components/policy/tools/generate_policy_source.py.orig	2026-01-14 08:33:23 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -37,9 +37,9 @@ PLATFORM_STRINGS = {
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
 
