--- tools/json_schema_compiler/feature_compiler.py.orig	2017-12-30 06:35:45.162972000 +0100
+++ tools/json_schema_compiler/feature_compiler.py	2017-12-30 06:37:35.101873000 +0100
@@ -211,6 +211,7 @@
         'enum_map': {
           'chromeos': 'Feature::CHROMEOS_PLATFORM',
           'linux': 'Feature::LINUX_PLATFORM',
+          'bsd': 'Feature::LINUX_PLATFORM',
           'mac': 'Feature::MACOSX_PLATFORM',
           'win': 'Feature::WIN_PLATFORM',
         }
