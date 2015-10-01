--- src/helma/framework/RequestTrans.java.orig	2015-09-16 00:39:16 UTC
+++ src/helma/framework/RequestTrans.java
@@ -602,10 +602,10 @@ public class RequestTrans implements Ser
         StringTokenizer tok;
 
         if (auth.startsWith("Basic ")) {
-            tok = new StringTokenizer(new String(Base64.decode((auth.substring(6)).toCharArray())),
+            tok = new StringTokenizer(new String(helma.util.Base64.decode((auth.substring(6)).toCharArray())),
                                       ":");
         } else {
-            tok = new StringTokenizer(new String(Base64.decode(auth.toCharArray())), ":");
+            tok = new StringTokenizer(new String(helma.util.Base64.decode(auth.toCharArray())), ":");
         }
 
         try {
