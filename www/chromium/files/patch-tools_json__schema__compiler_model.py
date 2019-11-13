--- tools/json_schema_compiler/model.py.orig	2019-10-21 19:07:27 UTC
+++ tools/json_schema_compiler/model.py
@@ -603,7 +603,7 @@ class Platforms(object):
   """
   CHROMEOS = _PlatformInfo("chromeos")
   CHROMEOS_TOUCH = _PlatformInfo("chromeos_touch")
-  LINUX = _PlatformInfo("linux")
+  LINUX = _PlatformInfo("bsd")
   MAC = _PlatformInfo("mac")
   WIN = _PlatformInfo("win")
 
