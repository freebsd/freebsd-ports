--- src/brave/common/importer/chrome_importer_utils.h.orig	2026-06-01 00:00:00 UTC
+++ src/brave/common/importer/chrome_importer_utils.h
@@ -21,8 +21,10 @@
 base::FilePath GetChromeUserDataFolder();
 base::FilePath GetChromeBetaUserDataFolder();
 base::FilePath GetChromeDevUserDataFolder();
-#if !BUILDFLAG(IS_LINUX)
-// Canary is not available on Linux
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
+// Canary is not available on Linux, and no more so on FreeBSD:
+// chrome_importer_utils_linux.cc, which is the file built here, has no
+// definition for it.
 base::FilePath GetCanaryUserDataFolder();
 #endif
 base::FilePath GetChromiumUserDataFolder();
