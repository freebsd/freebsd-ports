--- tools/json_schema_compiler/feature_compiler.py.orig	2022-04-01 07:48:30 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -267,6 +267,7 @@ FEATURE_GRAMMAR = ({
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
                 'fuchsia': 'Feature::FUCHSIA_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
