--- tools/json_schema_compiler/model.py.orig	2019-03-11 22:01:18 UTC
+++ tools/json_schema_compiler/model.py
@@ -602,7 +602,7 @@ class Platforms(object):
   """
   CHROMEOS = _PlatformInfo("chromeos")
   CHROMEOS_TOUCH = _PlatformInfo("chromeos_touch")
-  LINUX = _PlatformInfo("linux")
+  LINUX = _PlatformInfo("bsd")
   MAC = _PlatformInfo("mac")
   WIN = _PlatformInfo("win")
 
