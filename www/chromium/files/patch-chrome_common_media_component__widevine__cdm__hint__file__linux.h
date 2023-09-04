--- chrome/common/media/component_widevine_cdm_hint_file_linux.h.orig	2023-09-04 16:25:40 UTC
+++ chrome/common/media/component_widevine_cdm_hint_file_linux.h
@@ -15,7 +15,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_FREEBSD))
 #error "This file only applies to desktop Linux."
 #endif
 
