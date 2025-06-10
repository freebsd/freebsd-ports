--- src/3rdparty/chromium/components/policy/tools/generate_policy_source.py.orig	2024-04-19 13:02:56 UTC
+++ src/3rdparty/chromium/components/policy/tools/generate_policy_source.py
@@ -38,9 +38,9 @@ PLATFORM_STRINGS = {
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
 
