--- tools/json_schema_compiler/feature_compiler.py.orig	2019-03-11 22:01:18 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -205,6 +205,7 @@ FEATURE_GRAMMAR = (
         'enum_map': {
           'chromeos': 'Feature::CHROMEOS_PLATFORM',
           'linux': 'Feature::LINUX_PLATFORM',
+          'bsd': 'Feature::LINUX_PLATFORM',
           'mac': 'Feature::MACOSX_PLATFORM',
           'win': 'Feature::WIN_PLATFORM',
         }
