--- tools/json_schema_compiler/feature_compiler.py.orig	2026-08-31 10:59:09 UTC
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
