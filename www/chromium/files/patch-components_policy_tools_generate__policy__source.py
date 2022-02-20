--- components/policy/tools/generate_policy_source.py.orig	2022-02-07 13:39:41 UTC
+++ components/policy/tools/generate_policy_source.py
@@ -47,8 +47,10 @@ PLATFORM_STRINGS = {
     'ios': ['ios'],
     'chrome.win': ['win'],
     'chrome.linux': ['linux'],
+    'chrome.openbsd': ['openbsd'],
+    'chrome.freebsd': ['freebsd'],
     'chrome.mac': ['mac'],
-    'chrome.*': ['win', 'mac', 'linux', 'fuchsia'],
+    'chrome.*': ['win', 'mac', 'linux', 'fuchsia', 'openbsd', 'freebsd'],
     'chrome.win7': ['win'],
 }
 
