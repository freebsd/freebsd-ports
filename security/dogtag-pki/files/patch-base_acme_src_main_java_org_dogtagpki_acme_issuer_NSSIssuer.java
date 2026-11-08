--- base/acme/src/main/java/org/dogtagpki/acme/issuer/NSSIssuer.java.orig	2026-07-28 16:37:15 UTC
+++ base/acme/src/main/java/org/dogtagpki/acme/issuer/NSSIssuer.java
@@ -114,7 +114,7 @@ public class NSSIssuer extends ACMEIssuer {
         this.hash = hash;
 
         String extensions = config.getParameter("extensions");
-        if (extensions == null) extensions = "/usr/share/pki/acme/issuer/nss/sslserver.conf";
+        if (extensions == null) extensions = "/usr/local/share/pki/acme/issuer/nss/sslserver.conf";
         logger.info("- extensions: " + extensions);
 
         Path extPath = instanceDir.resolve(extensions);
