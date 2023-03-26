--- src/bin/bat/main.rs.orig	2023-03-26 13:03:26.858196000 +0200
+++ src/bin/bat/main.rs	2023-03-26 13:03:44.520025000 +0200
@@ -246,7 +246,6 @@
 
     let mut report = bugreport!()
         .info(SoftwareVersion::default())
-        .info(OperatingSystem::default())
         .info(CommandLine::default())
         .info(EnvironmentVariables::list(&[
             "SHELL",
