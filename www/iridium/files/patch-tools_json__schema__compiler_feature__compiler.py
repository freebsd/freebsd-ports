--- tools/json_schema_compiler/feature_compiler.py.orig	2024-11-04 08:56:03 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -292,6 +292,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
