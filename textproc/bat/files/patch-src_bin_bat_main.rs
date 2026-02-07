--- src/bin/bat/main.rs.orig	2025-01-21 16:18:28 UTC
+++ src/bin/bat/main.rs
@@ -290,7 +290,6 @@ fn invoke_bugreport(app: &App, cache_dir: &Path) {
 
     let mut report = bugreport!()
         .info(SoftwareVersion::default())
-        .info(OperatingSystem::default())
         .info(CommandLine::default())
         .info(EnvironmentVariables::list(&[
             "BAT_CACHE_PATH",
