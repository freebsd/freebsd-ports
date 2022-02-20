--- extensions/shell/common/switches.cc.orig	2022-02-07 13:39:41 UTC
+++ extensions/shell/common/switches.cc
@@ -22,7 +22,7 @@ const char kAppShellPreferredNetwork[] = "app-shell-pr
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 // The directory breakpad should store minidumps in.
 const char kCrashDumpsDir[] = "crash-dumps-dir";
 
