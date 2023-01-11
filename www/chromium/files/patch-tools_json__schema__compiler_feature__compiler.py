--- tools/json_schema_compiler/feature_compiler.py.orig	2023-01-11 09:17:16 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -268,6 +268,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
