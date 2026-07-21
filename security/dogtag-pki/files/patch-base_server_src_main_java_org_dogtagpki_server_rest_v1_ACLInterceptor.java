--- base/server/src/main/java/org/dogtagpki/server/rest/v1/ACLInterceptor.java.orig	2025-08-05 19:20:05 UTC
+++ base/server/src/main/java/org/dogtagpki/server/rest/v1/ACLInterceptor.java
@@ -89,7 +89,7 @@ public class ACLInterceptor implements ContainerReques
         String subsystem = context.startsWith("/") ? context.substring(1) : context;
 
         // load default mapping
-        String defaultMapping = "/usr/share/pki/" + subsystem + "/conf/acl.properties";
+        String defaultMapping = "/usr/local/share/pki/" + subsystem + "/conf/acl.properties";
         logger.debug("ACLInterceptor: loading " + defaultMapping);
         try (FileReader in = new FileReader(defaultMapping)) {
             properties.load(in);
