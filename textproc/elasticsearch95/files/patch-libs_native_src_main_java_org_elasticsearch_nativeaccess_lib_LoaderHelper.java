--- libs/native/src/main/java/org/elasticsearch/nativeaccess/lib/LoaderHelper.java.orig	2026-10-28 20:24:18 UTC
+++ libs/native/src/main/java/org/elasticsearch/nativeaccess/lib/LoaderHelper.java
@@ -37,6 +37,8 @@ public class LoaderHelper {
             os = "linux";
         } else if (osname.startsWith("Mac OS")) {
             os = "darwin";
+        } else if (osname.startsWith("FreeBSD")) {
+            os = "freebsd";
         } else {
             os = "unsupported_os[" + osname + "]";
         }
