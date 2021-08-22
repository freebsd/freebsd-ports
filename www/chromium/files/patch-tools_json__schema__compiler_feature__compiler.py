--- tools/json_schema_compiler/feature_compiler.py.orig	2021-07-19 18:45:43 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -259,6 +259,7 @@ FEATURE_GRAMMAR = ({
                 'chromeos': 'Feature::CHROMEOS_PLATFORM',
                 'lacros': 'Feature::LACROS_PLATFORM',
                 'linux': 'Feature::LINUX_PLATFORM',
+                'bsd': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
             }
