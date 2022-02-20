--- tools/json_schema_compiler/cpp_bundle_generator.py.orig	2022-02-07 13:39:41 UTC
+++ tools/json_schema_compiler/cpp_bundle_generator.py
@@ -154,7 +154,7 @@ class CppBundleGenerator(object):
         # defined(OS_CHROMEOS) && BUILDFLAG(IS_CHROMEOS_LACROS).
         ifdefs.append('BUILDFLAG(IS_CHROMEOS_LACROS)')
       elif platform == Platforms.LINUX:
-        ifdefs.append('(defined(OS_LINUX) && !defined(OS_CHROMEOS))')
+        ifdefs.append('(defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)')
       elif platform == Platforms.MAC:
         ifdefs.append('defined(OS_MAC)')
       elif platform == Platforms.WIN:
