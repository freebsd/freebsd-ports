--- xmppserver/src/main/java/org/jivesoftware/database/JNDIDataSourceProvider.java.orig	2026-03-17 18:25:26 UTC
+++ xmppserver/src/main/java/org/jivesoftware/database/JNDIDataSourceProvider.java
@@ -52,7 +52,7 @@ public class JNDIDataSourceProvider implements Connect
      * Keys of JNDI properties to query PropertyManager for.
      */
     public static final String[] jndiPropertyKeys = {
-        Context.APPLET,
+//        Context.APPLET,
         Context.AUTHORITATIVE,
         Context.BATCHSIZE,
         Context.DNS_URL,
