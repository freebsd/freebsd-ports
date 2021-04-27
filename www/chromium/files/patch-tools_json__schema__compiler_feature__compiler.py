--- tools/json_schema_compiler/feature_compiler.py.orig	2021-04-14 18:41:36 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -257,6 +257,7 @@ FEATURE_GRAMMAR = ({
                 'chromeos': 'Feature::CHROMEOS_PLATFORM',
                 'lacros': 'Feature::LACROS_PLATFORM',
                 'linux': 'Feature::LINUX_PLATFORM',
+                'bsd': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
             }
