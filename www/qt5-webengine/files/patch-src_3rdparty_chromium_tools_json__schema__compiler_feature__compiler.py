--- src/3rdparty/chromium/tools/json_schema_compiler/feature_compiler.py.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/tools/json_schema_compiler/feature_compiler.py
@@ -243,6 +243,7 @@ FEATURE_GRAMMAR = ({
                 'chromeos': 'Feature::CHROMEOS_PLATFORM',
                 'lacros': 'Feature::LACROS_PLATFORM',
                 'linux': 'Feature::LINUX_PLATFORM',
+                'bsd': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
             }
