--- chrome/browser/first_run/first_run_internal_linux.cc.orig	2026-01-16 14:21:21 UTC
+++ chrome/browser/first_run/first_run_internal_linux.cc
@@ -20,7 +20,13 @@ bool IsOrganicFirstRun() {
 base::FilePath InitialPrefsPath() {
   // The standard location of the initial prefs is next to the chrome binary.
   base::FilePath dir_exe;
+#if BUILDFLAG(IS_OPENBSD)
+  dir_exe = base::FilePath("/etc/iridium");
+#elif BUILDFLAG(IS_FREEBSD)
+  dir_exe = base::FilePath("/usr/local/etc/iridium");
+#else
   dir_exe = base::FilePath("/etc/iridium-browser");
+#endif
   return installer::InitialPreferences::Path(dir_exe);
 }
 
