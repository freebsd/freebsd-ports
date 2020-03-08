--- tools/json_schema_compiler/feature_compiler.py.orig	2020-03-03 18:54:06 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -218,6 +218,7 @@ FEATURE_GRAMMAR = (
         'enum_map': {
           'chromeos': 'Feature::CHROMEOS_PLATFORM',
           'linux': 'Feature::LINUX_PLATFORM',
+          'bsd': 'Feature::LINUX_PLATFORM',
           'mac': 'Feature::MACOSX_PLATFORM',
           'win': 'Feature::WIN_PLATFORM',
         }
