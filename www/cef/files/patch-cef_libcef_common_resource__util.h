--- cef/libcef/common/resource_util.h.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/common/resource_util.h
@@ -21,7 +21,7 @@ base::FilePath GetResourcesDir();
 void OverrideUserDataDir(CefSettings* settings,
                          const base::CommandLine* command_line);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Look for binary files (*.bin, *.dat, *.pak, chrome-sandbox, libGLESv2.so,
 // libEGL.so, locales/*.pak, swiftshader/*.so) next to libcef instead of the exe
 // on Linux. This is already the default on Windows.
