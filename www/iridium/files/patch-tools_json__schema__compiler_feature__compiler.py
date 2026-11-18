--- tools/json_schema_compiler/feature_compiler.py.orig	2026-11-17 21:17:00 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -251,6 +251,8 @@ FEATURE_GRAMMAR = {
         'linux': 'Feature::LINUX_PLATFORM',
         'mac': 'Feature::MACOSX_PLATFORM',
         'win': 'Feature::WIN_PLATFORM',
+        'openbsd': 'Feature::LINUX_PLATFORM',
+        'freebsd': 'Feature::LINUX_PLATFORM',
       }
     }
   },
