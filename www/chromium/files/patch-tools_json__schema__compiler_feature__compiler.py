--- tools/json_schema_compiler/feature_compiler.py.orig	2026-09-25 15:26:43 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -250,6 +250,8 @@ FEATURE_GRAMMAR = {
         'linux': 'Feature::LINUX_PLATFORM',
         'mac': 'Feature::MACOSX_PLATFORM',
         'win': 'Feature::WIN_PLATFORM',
+        'openbsd': 'Feature::LINUX_PLATFORM',
+        'freebsd': 'Feature::LINUX_PLATFORM',
       }
     }
   },
