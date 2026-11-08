--- tools/json_schema_compiler/feature_compiler.py.orig	2026-10-18 13:29:39 UTC
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
