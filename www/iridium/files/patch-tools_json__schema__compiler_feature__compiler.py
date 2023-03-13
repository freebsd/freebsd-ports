--- tools/json_schema_compiler/feature_compiler.py.orig	2023-03-13 07:33:08 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -266,6 +266,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
