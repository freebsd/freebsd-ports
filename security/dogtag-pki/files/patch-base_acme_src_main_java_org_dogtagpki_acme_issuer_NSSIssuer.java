--- base/acme/src/main/java/org/dogtagpki/acme/issuer/NSSIssuer.java.orig	2025-08-05 19:20:05 UTC
+++ base/acme/src/main/java/org/dogtagpki/acme/issuer/NSSIssuer.java
@@ -111,7 +111,7 @@ public class NSSIssuer extends ACMEIssuer {
         }
 
         String extensions = config.getParameter("extensions");
-        if (extensions == null) extensions = "/usr/share/pki/acme/issuer/nss/sslserver.conf";
+        if (extensions == null) extensions = "/usr/local/share/pki/acme/issuer/nss/sslserver.conf";
         logger.info("- extensions: " + extensions);
 
         Path extPath = instanceDir.resolve(extensions);
