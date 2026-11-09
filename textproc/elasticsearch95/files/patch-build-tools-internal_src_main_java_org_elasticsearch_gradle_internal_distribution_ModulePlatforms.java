--- build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/distribution/ModulePlatforms.java.orig	2026-10-28 20:24:18 UTC
+++ build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/distribution/ModulePlatforms.java
@@ -26,7 +26,8 @@ public final class ModulePlatforms {
         "linux-aarch64",
         "windows-x86_64",
         "darwin-x86_64",
-        "darwin-aarch64"
+        "darwin-aarch64",
+        "freebsd-x86_64"
     );
 
     private ModulePlatforms() {}
