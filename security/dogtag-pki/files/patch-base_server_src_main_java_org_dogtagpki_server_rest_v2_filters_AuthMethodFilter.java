--- base/server/src/main/java/org/dogtagpki/server/rest/v2/filters/AuthMethodFilter.java.orig	2025-08-05 19:20:05 UTC
+++ base/server/src/main/java/org/dogtagpki/server/rest/v2/filters/AuthMethodFilter.java
@@ -116,7 +116,7 @@ public abstract class AuthMethodFilter extends HttpFil
         String subsystem = context.startsWith("/") ? context.substring(1) : context;
 
         // load default mapping
-        Path defaultMappingAuth = Paths.get("/usr/share/pki", subsystem, "conf", "auth-method.properties");
+        Path defaultMappingAuth = Paths.get("/usr/local/share/pki", subsystem, "conf", "auth-method.properties");
         File defaultMapping = defaultMappingAuth.toFile();
         logger.debug("AuthMethodFilter: loading {}", defaultMapping);
         try (FileReader in = new FileReader(defaultMapping)) {
