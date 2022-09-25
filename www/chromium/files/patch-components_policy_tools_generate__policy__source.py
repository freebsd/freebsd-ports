--- components/policy/tools/generate_policy_source.py.orig	2022-09-24 10:57:32 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -50,8 +50,10 @@ PLATFORM_STRINGS = {
     'fuchsia': ['fuchsia'],
     'chrome.win': ['win'],
     'chrome.linux': ['linux'],
+    'chrome.openbsd': ['openbsd'],
+    'chrome.freebsd': ['freebsd'],
     'chrome.mac': ['mac'],
-    'chrome.*': ['win', 'mac', 'linux'],
+    'chrome.*': ['win', 'mac', 'linux', 'openbsd', 'freebsd'],
     'chrome.win7': ['win'],
 }
 
