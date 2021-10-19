--- tools/json_schema_compiler/feature_compiler.py.orig	2021-09-24 04:26:37 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -258,7 +258,9 @@ FEATURE_GRAMMAR = ({
     'platforms': {
         list: {
             'enum_map': {
+                'bsd': 'Feature::LINUX_PLATFORM',
                 'chromeos': 'Feature::CHROMEOS_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
                 'lacros': 'Feature::LACROS_PLATFORM',
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
