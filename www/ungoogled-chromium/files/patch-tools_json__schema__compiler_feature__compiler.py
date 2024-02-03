--- tools/json_schema_compiler/feature_compiler.py.orig	2024-02-03 15:42:55 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -273,6 +273,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
