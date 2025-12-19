--- src/3rdparty/chromium/tools/json_schema_compiler/feature_compiler.py.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/tools/json_schema_compiler/feature_compiler.py
@@ -290,6 +290,8 @@ FEATURE_GRAMMAR = ({
                 'linux': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
+                'openbsd': 'Feature::LINUX_PLATFORM',
+                'freebsd': 'Feature::LINUX_PLATFORM',
             }
         }
     },
