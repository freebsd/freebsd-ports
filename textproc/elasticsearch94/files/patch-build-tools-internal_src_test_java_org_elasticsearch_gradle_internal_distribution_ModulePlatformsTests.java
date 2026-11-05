--- build-tools-internal/src/test/java/org/elasticsearch/gradle/internal/distribution/ModulePlatformsTests.java.orig	2026-10-28 20:24:18 UTC
+++ build-tools-internal/src/test/java/org/elasticsearch/gradle/internal/distribution/ModulePlatformsTests.java
@@ -25,17 +25,18 @@ public class ModulePlatformsTests {
         assertEquals("windows-x86_64", ModulePlatforms.directory("windows", "x64"));
         assertEquals("darwin-x86_64", ModulePlatforms.directory("darwin", "x64"));
         assertEquals("darwin-aarch64", ModulePlatforms.directory("darwin", "aarch64"));
+        assertEquals("freebsd-x86_64", ModulePlatforms.directory("freebsd", "x64"));
         assertThrows(IllegalArgumentException.class, () -> ModulePlatforms.directory("windows", "aarch64"));
     }
 
     @Test
     public void excludedDirectoriesKeepOnlyTargetPlatform() {
         assertEquals(
-            List.of("linux-aarch64", "windows-x86_64", "darwin-x86_64", "darwin-aarch64"),
+            List.of("linux-aarch64", "windows-x86_64", "darwin-x86_64", "darwin-aarch64", "freebsd-x86_64"),
             ModulePlatforms.excludedDirectories("linux", "x64")
         );
         assertEquals(
-            List.of("linux-x86_64", "linux-aarch64", "windows-x86_64", "darwin-x86_64"),
+            List.of("linux-x86_64", "linux-aarch64", "windows-x86_64", "darwin-x86_64", "freebsd-x86_64"),
             ModulePlatforms.excludedDirectories("darwin", "aarch64")
         );
     }
