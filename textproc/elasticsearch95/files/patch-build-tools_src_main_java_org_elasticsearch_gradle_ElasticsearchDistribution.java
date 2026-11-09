--- build-tools/src/main/java/org/elasticsearch/gradle/ElasticsearchDistribution.java.orig	2026-10-28 21:29:53 UTC
+++ build-tools/src/main/java/org/elasticsearch/gradle/ElasticsearchDistribution.java
@@ -27,7 +27,8 @@ public class ElasticsearchDistribution implements Buil
     public enum Platform {
         LINUX,
         WINDOWS,
-        DARWIN;
+        DARWIN,
+        FREEBSD;
 
         @Override
         public String toString() {
@@ -40,6 +41,7 @@ public class ElasticsearchDistribution implements Buil
         .onLinux(() -> Platform.LINUX)
         .onWindows(() -> Platform.WINDOWS)
         .onMac(() -> Platform.DARWIN)
+        .onFreeBSD(() -> Platform.FREEBSD)
         .supply();
 
     private final String name;
