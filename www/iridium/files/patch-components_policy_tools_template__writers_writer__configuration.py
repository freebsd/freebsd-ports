--- components/policy/tools/template_writers/writer_configuration.py.orig	2025-12-10 15:04:57 UTC
+++ components/policy/tools/template_writers/writer_configuration.py
@@ -59,7 +59,7 @@ def GetConfigurationForBuild(defines):
             },
         },
         'admx_prefix': 'chromium',
-        'linux_policy_path': '/etc/iridium-browser/policies/',
+        'linux_policy_path': '/etc/iridium/policies/',
         'bundle_id': 'org.chromium',
     }
   elif '_google_chrome' in defines or '_is_chrome_for_testing_branded' in defines:
