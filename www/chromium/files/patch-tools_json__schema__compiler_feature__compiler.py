--- tools/json_schema_compiler/feature_compiler.py.orig	2022-02-07 13:39:41 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -264,6 +264,7 @@ FEATURE_GRAMMAR = ({
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
                 'fuchsia': 'Feature::FUCHSIA_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
