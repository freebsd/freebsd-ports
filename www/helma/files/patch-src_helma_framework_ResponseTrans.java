--- src/helma/framework/ResponseTrans.java.orig	2015-09-16 00:39:16 UTC
+++ src/helma/framework/ResponseTrans.java
@@ -714,7 +714,7 @@ public final class ResponseTrans extends
                 // if (contentType != null)
                 //     digest.update (contentType.getBytes());
                 byte[] b = digest.digest(response);
-                etag = "\"" + new String(Base64.encode(b)) + "\"";
+                etag = "\"" + new String(helma.util.Base64.encode(b)) + "\"";
                 // only set response to 304 not modified if no cookies were set
                 if (reqtrans.hasETag(etag) && countCookies() == 0) {
                     response = new byte[0];
@@ -891,7 +891,7 @@ public final class ResponseTrans extends
         // generation sensitive to changes in the app
         byte[] b = digest.digest(MD5Encoder.toBytes(app.getChecksum()));
 
-        setETag(new String(Base64.encode(b)));
+        setETag(new String(helma.util.Base64.encode(b)));
     }
 
     /**
@@ -1164,4 +1164,4 @@ public final class ResponseTrans extends
     public void setRealm(String realm) {
         this.realm = realm;
     }
-}
\ No newline at end of file
+}
