--- tools/json_schema_compiler/feature_compiler.py.orig	2019-06-04 18:55:48 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -212,6 +212,7 @@ FEATURE_GRAMMAR = (
         'enum_map': {
           'chromeos': 'Feature::CHROMEOS_PLATFORM',
           'linux': 'Feature::LINUX_PLATFORM',
+          'bsd': 'Feature::LINUX_PLATFORM',
           'mac': 'Feature::MACOSX_PLATFORM',
           'win': 'Feature::WIN_PLATFORM',
         }
