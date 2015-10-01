--- src/helma/servlet/AbstractServletClient.java.orig	2015-09-16 00:39:16 UTC
+++ src/helma/servlet/AbstractServletClient.java
@@ -510,7 +510,7 @@ public abstract class AbstractServletCli
             checksum[i] = (byte) (n);
             n >>>= 8;
         }
-        String etag = "\"" + new String(Base64.encode(checksum)) + "\"";
+        String etag = "\"" + new String(helma.util.Base64.encode(checksum)) + "\"";
         res.setHeader("ETag", etag);
         String etagHeader = req.getHeader("If-None-Match");
         if (etagHeader != null) {
