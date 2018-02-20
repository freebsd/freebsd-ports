--- tools/json_schema_compiler/model.py.orig	2017-12-30 06:35:55.601371000 +0100
+++ tools/json_schema_compiler/model.py	2017-12-30 06:36:37.374966000 +0100
@@ -599,7 +599,7 @@
   """
   CHROMEOS = _PlatformInfo("chromeos")
   CHROMEOS_TOUCH = _PlatformInfo("chromeos_touch")
-  LINUX = _PlatformInfo("linux")
+  LINUX = _PlatformInfo("bsd")
   MAC = _PlatformInfo("mac")
   WIN = _PlatformInfo("win")
 
