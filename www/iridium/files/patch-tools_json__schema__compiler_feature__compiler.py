--- tools/json_schema_compiler/feature_compiler.py.orig	2024-06-25 12:08:48 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -277,6 +277,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
