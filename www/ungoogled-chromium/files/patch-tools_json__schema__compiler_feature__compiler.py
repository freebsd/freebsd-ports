--- tools/json_schema_compiler/feature_compiler.py.orig	2023-06-05 19:39:05 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -272,6 +272,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
