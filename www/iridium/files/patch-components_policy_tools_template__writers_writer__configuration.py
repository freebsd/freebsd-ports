--- components/policy/tools/template_writers/writer_configuration.py.orig	2026-11-17 21:17:00 UTC
+++ components/policy/tools/template_writers/writer_configuration.py
@@ -57,7 +57,7 @@ def GetConfigurationForBuild(defines):
         },
       },
       'admx_prefix': 'chromium',
-      'linux_policy_path': '/etc/iridium-browser/policies/',
+      'linux_policy_path': '/etc/iridium/policies/',
       'bundle_id': 'org.chromium',
     }
   elif (
