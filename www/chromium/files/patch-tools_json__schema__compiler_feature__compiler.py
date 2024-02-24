--- tools/json_schema_compiler/feature_compiler.py.orig	2024-02-23 21:04:38 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -276,6 +276,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
