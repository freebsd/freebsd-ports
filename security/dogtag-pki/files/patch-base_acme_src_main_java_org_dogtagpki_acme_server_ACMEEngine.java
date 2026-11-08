--- base/acme/src/main/java/org/dogtagpki/acme/server/ACMEEngine.java.orig	2025-08-05 19:20:05 UTC
+++ base/acme/src/main/java/org/dogtagpki/acme/server/ACMEEngine.java
@@ -220,7 +220,7 @@ public class ACMEEngine extends CMSEngine {
         File configFile = new File(filename);
 
         if (!configFile.exists()) {
-            configFile = new File("/usr/share/pki/acme/conf/engine.conf");
+            configFile = new File("/usr/local/share/pki/acme/conf/engine.conf");
         }
 
         logger.info("Loading ACME engine config from " + configFile);
@@ -261,7 +261,7 @@ public class ACMEEngine extends CMSEngine {
         File metadataConfigFile = new File(filename);
 
         if (!metadataConfigFile.exists()) {
-            metadataConfigFile = new File("/usr/share/pki/acme/conf/metadata.conf");
+            metadataConfigFile = new File("/usr/local/share/pki/acme/conf/metadata.conf");
         }
 
         logger.info("Loading ACME metadata from " + metadataConfigFile);
@@ -304,7 +304,7 @@ public class ACMEEngine extends CMSEngine {
         File validatorsConfigFile = new File(filename);
 
         if (!validatorsConfigFile.exists()) {
-            validatorsConfigFile = new File("/usr/share/pki/acme/conf/validators.conf");
+            validatorsConfigFile = new File("/usr/local/share/pki/acme/conf/validators.conf");
         }
 
         logger.info("Loading ACME validators config from " + validatorsConfigFile);
@@ -365,7 +365,7 @@ public class ACMEEngine extends CMSEngine {
         File schedulerConfigFile = new File(filename);
 
         if (!schedulerConfigFile.exists()) {
-            schedulerConfigFile = new File("/usr/share/pki/acme/conf/scheduler.conf");
+            schedulerConfigFile = new File("/usr/local/share/pki/acme/conf/scheduler.conf");
         }
 
         logger.info("Loading ACME scheduler config from " + schedulerConfigFile);
