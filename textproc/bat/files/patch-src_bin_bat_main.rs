--- src/bin/bat/main.rs.orig	2021-07-19 20:42:50 UTC
+++ src/bin/bat/main.rs
@@ -233,7 +233,6 @@ fn run() -> Result<bool> {
 
         let report = bugreport!()
             .info(SoftwareVersion::default())
-            .info(OperatingSystem::default())
             .info(CommandLine::default())
             .info(EnvironmentVariables::list(&[
                 "SHELL",
