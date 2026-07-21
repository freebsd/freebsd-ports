--- base/server/src/main/java/org/dogtagpki/server/rest/v1/AuthMethodInterceptor.java.orig	2025-08-05 19:20:05 UTC
+++ base/server/src/main/java/org/dogtagpki/server/rest/v1/AuthMethodInterceptor.java
@@ -71,7 +71,7 @@ public class AuthMethodInterceptor implements Containe
         String subsystem = context.startsWith("/") ? context.substring(1) : context;
 
         // load default mapping
-        String defaultMapping = "/usr/share/pki/" + subsystem + "/conf/auth-method.properties";
+        String defaultMapping = "/usr/local/share/pki/" + subsystem + "/conf/auth-method.properties";
         logger.debug("AuthMethodInterceptor: loading " + defaultMapping);
         try (FileReader in = new FileReader(defaultMapping)) {
             properties.load(in);
