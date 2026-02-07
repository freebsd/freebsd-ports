--- src/3rdparty/chromium/tools/json_schema_compiler/cpp_bundle_generator.py.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/tools/json_schema_compiler/cpp_bundle_generator.py
@@ -144,7 +144,7 @@ class CppBundleGenerator(object):
         # BUILDFLAG(IS_CHROMEOS) && BUILDFLAG(IS_CHROMEOS_LACROS).
         ifdefs.append('BUILDFLAG(IS_CHROMEOS_LACROS)')
       elif platform == Platforms.LINUX:
-        ifdefs.append('BUILDFLAG(IS_LINUX)')
+        ifdefs.append('BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)')
       elif platform == Platforms.MAC:
         ifdefs.append('BUILDFLAG(IS_MAC)')
       elif platform == Platforms.WIN:
