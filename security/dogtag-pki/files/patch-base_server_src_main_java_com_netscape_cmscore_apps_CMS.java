--- base/server/src/main/java/com/netscape/cmscore/apps/CMS.java.orig	2025-08-05 19:20:05 UTC
+++ base/server/src/main/java/com/netscape/cmscore/apps/CMS.java
@@ -44,7 +44,7 @@ public final class CMS {
     public static final Logger logger = LoggerFactory.getLogger(CMS.class);
 
     // product name is provided by the server theme package
-    private static final String PRODUCT_NAME_FILE = "/usr/share/pki/CS_SERVER_VERSION";
+    private static final String PRODUCT_NAME_FILE = "/usr/local/share/pki/CS_SERVER_VERSION";
 
     public static final int DEBUG_OBNOXIOUS = 1;
     public static final int DEBUG_VERBOSE = 5;
@@ -56,7 +56,7 @@ public final class CMS {
     public static final int RUNNING_MODE = 1;
 
     /**
-     * Return the product name from /usr/share/pki/CS_SERVER_VERSION
+     * Return the product name from /usr/local/share/pki/CS_SERVER_VERSION
      * which is provided by the server theme package.
      */
     public static String getProductName() throws Exception {
