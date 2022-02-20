--- extensions/shell/common/switches.h.orig	2022-02-07 13:39:41 UTC
+++ extensions/shell/common/switches.h
@@ -20,7 +20,7 @@ extern const char kAppShellPreferredNetwork[];
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 extern const char kCrashDumpsDir[];
 extern const char kEnableReporting[];
 #endif
