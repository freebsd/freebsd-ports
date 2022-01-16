--- src/bin/bat/main.rs.orig	2022-01-08 17:01:20.000000000 +0100
+++ src/bin/bat/main.rs	2022-01-13 23:14:55.825571000 +0100
@@ -232,7 +232,6 @@
 
     let mut report = bugreport!()
         .info(SoftwareVersion::default())
-        .info(OperatingSystem::default())
         .info(CommandLine::default())
         .info(EnvironmentVariables::list(&[
             "SHELL",
