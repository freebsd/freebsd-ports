--- build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/Jdk.java.orig	2026-10-28 21:29:53 UTC
+++ build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/Jdk.java
@@ -26,7 +26,7 @@ public class Jdk implements Buildable, Iterable<File> 
 
     private static final List<String> ALLOWED_ARCHITECTURES = List.of("aarch64", "x64");
     private static final List<String> ALLOWED_VENDORS = List.of("adoptium", "openjdk", "zulu");
-    private static final List<String> ALLOWED_PLATFORMS = List.of("darwin", "linux", "windows", "mac");
+    private static final List<String> ALLOWED_PLATFORMS = List.of("darwin", "linux", "windows", "mac", "freebsd");
     /**
      * Matches JDK versions of the form {@code feature[.interim.update[.patch[.extra...]]]+build[@hash]} as defined by JEP 322,
      * e.g. {@code 27+35@hash} or {@code 27.0.1.0.2+1@hash}.
