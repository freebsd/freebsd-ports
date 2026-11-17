--- components/policy/tools/generate_policy_source.py.orig	2026-11-17 11:49:09 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -36,9 +36,9 @@ PLATFORM_STRINGS = {
   'ios': ['ios'],
   'fuchsia': ['fuchsia'],
   'chrome.win': ['win'],
-  'chrome.linux': ['linux'],
+  'chrome.linux': ['linux', 'openbsd', 'freebsd'],
   'chrome.mac': ['mac'],
-  'chrome.*': ['win', 'mac', 'linux'],
+  'chrome.*': ['win', 'mac', 'linux', 'openbsd', 'freebsd'],
   'chrome.win7': ['win'],
 }
 
