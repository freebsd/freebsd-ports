--- base/server/src/main/java/org/dogtagpki/server/rest/v2/filters/ACLFilter.java.orig	2025-08-05 19:20:05 UTC
+++ base/server/src/main/java/org/dogtagpki/server/rest/v2/filters/ACLFilter.java
@@ -136,7 +136,7 @@ public abstract class ACLFilter extends HttpFilter {
         String subsystem = context.startsWith("/") ? context.substring(1) : context;
 
         // load default mapping
-        Path defaultMappingACL = Paths.get("/usr/share/pki", subsystem, "conf", "acl.properties");
+        Path defaultMappingACL = Paths.get("/usr/local/share/pki", subsystem, "conf", "acl.properties");
         File defaultMapping = defaultMappingACL.toFile();
         logger.debug("ACLFilter: loading {}", defaultMappingACL);
         try (FileReader in = new FileReader(defaultMapping)) {
