--- base/acme/src/main/java/org/dogtagpki/acme/database/PostgreSQLDatabase.java.orig	2025-08-05 19:20:05 UTC
+++ base/acme/src/main/java/org/dogtagpki/acme/database/PostgreSQLDatabase.java
@@ -70,7 +70,7 @@ public class PostgreSQLDatabase extends ACMEDatabase {
 
         String statementsFilename = info.getProperty(
                 "statements",
-                "/usr/share/pki/acme/database/postgresql/statements.conf");
+                "/usr/local/share/pki/acme/database/postgresql/statements.conf");
 
         logger.info("Loading statements from " + statementsFilename);
 
@@ -153,7 +153,7 @@ public class PostgreSQLDatabase extends ACMEDatabase {
 
         logger.info("Setting up database");
 
-        String filename = "/usr/share/pki/acme/database/postgresql/create.sql";
+        String filename = "/usr/local/share/pki/acme/database/postgresql/create.sql";
         String content = new String(Files.readAllBytes(Paths.get(filename)));
 
         String[] statements = content.split(";");
