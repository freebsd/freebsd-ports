--- tools/json_schema_compiler/model.py.orig	2021-07-19 18:45:43 UTC
+++ tools/json_schema_compiler/model.py
@@ -872,7 +872,7 @@ class Platforms(object):
   """
   CHROMEOS = _PlatformInfo("chromeos")
   LACROS = _PlatformInfo("lacros")
-  LINUX = _PlatformInfo("linux")
+  LINUX = _PlatformInfo("bsd")
   MAC = _PlatformInfo("mac")
   WIN = _PlatformInfo("win")
 
