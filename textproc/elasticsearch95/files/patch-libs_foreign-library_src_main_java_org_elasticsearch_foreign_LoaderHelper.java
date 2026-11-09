--- libs/foreign-library/src/main/java/org/elasticsearch/foreign/LoaderHelper.java.orig	2026-10-28 21:58:41 UTC
+++ libs/foreign-library/src/main/java/org/elasticsearch/foreign/LoaderHelper.java
@@ -37,6 +37,8 @@ public class LoaderHelper {
             os = "linux";
         } else if (osname.startsWith("Mac OS")) {
             os = "darwin";
+        } else if (osname.startsWith("FreeBSD")) {
+            os = "freebsd";
         } else {
             os = "unsupported_os[" + osname + "]";
         }
