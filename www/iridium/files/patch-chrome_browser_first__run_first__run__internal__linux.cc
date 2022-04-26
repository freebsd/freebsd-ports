--- chrome/browser/first_run/first_run_internal_linux.cc.orig	2022-04-03 12:23:22 UTC
+++ chrome/browser/first_run/first_run_internal_linux.cc
@@ -21,7 +21,13 @@ bool IsOrganicFirstRun() {
 base::FilePath InitialPrefsPath() {
   // The standard location of the initial prefs is next to the chrome binary.
   base::FilePath initial_prefs;
+#if BUILDFLAG(IS_OPENBSD)
+  initial_prefs = base::FilePath("/etc/iridium");
+#elif BUILDFLAG(IS_FREEBSD)
+  initial_prefs = base::FilePath("/usr/local/etc/iridium");
+#else
   initial_prefs = base::FilePath("/etc/iridium-browser");
+#endif
   base::FilePath new_path = initial_prefs.AppendASCII(installer::kInitialPrefs);
   if (base::PathIsReadable(new_path))
     return new_path;
