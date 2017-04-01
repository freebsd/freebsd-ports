* Silence a syntax warning

--- modules.h.orig	2015-08-12 07:03:15 UTC
+++ modules.h
@@ -144,7 +144,7 @@ struct SensorModul SensorModulList[] = {
   { "Uptime", initUptime, exitUptime, NULLIVFUNC, NULLVVFUNC, 0, NULLTIME },
 #endif /* OSTYPE_Linux */
 
-#if defined OSTYPE_FreeBSD || defined OSTYPE_DragonFly
+#if defined(OSTYPE_FreeBSD) || defined(OSTYPE_DragonFly)
   { "Acpi", initACPI, exitACPI, updateACPI, NULLVVFUNC, 0, NULLTIME },
   #ifdef __i386__
     { "Apm", initApm, exitApm, updateApm, NULLVVFUNC, 0, NULLTIME },
