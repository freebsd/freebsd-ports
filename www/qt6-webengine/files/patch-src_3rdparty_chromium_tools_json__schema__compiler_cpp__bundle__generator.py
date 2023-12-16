--- src/3rdparty/chromium/tools/json_schema_compiler/cpp_bundle_generator.py.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/tools/json_schema_compiler/cpp_bundle_generator.py
@@ -149,7 +149,7 @@ class CppBundleGenerator(object):
         # BUILDFLAG(IS_CHROMEOS) && BUILDFLAG(IS_CHROMEOS_LACROS).
         ifdefs.append('BUILDFLAG(IS_CHROMEOS_LACROS)')
       elif platform == Platforms.LINUX:
-        ifdefs.append('BUILDFLAG(IS_LINUX)')
+        ifdefs.append('BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)')
       elif platform == Platforms.MAC:
         ifdefs.append('BUILDFLAG(IS_MAC)')
       elif platform == Platforms.WIN:
