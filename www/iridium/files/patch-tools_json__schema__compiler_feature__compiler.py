--- tools/json_schema_compiler/feature_compiler.py.orig	2022-10-05 07:34:01 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -268,6 +268,8 @@ FEATURE_GRAMMAR = ({
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
                 'fuchsia': 'Feature::FUCHSIA_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
