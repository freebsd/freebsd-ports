--- qa/packaging/src/test/java/org/elasticsearch/packaging/test/ConfigurationTests.java.orig	2026-10-28 21:29:53 UTC
+++ qa/packaging/src/test/java/org/elasticsearch/packaging/test/ConfigurationTests.java
@@ -75,6 +75,7 @@ public class ConfigurationTests extends PackagingTestC
         Path data = createTempDir("temp-data");
         // Make the data directory writeable
         Platforms.onLinux(() -> Files.setPosixFilePermissions(data, fromString("rwxrwxrwx")));
+        Platforms.onFreeBSD(() -> Files.setPosixFilePermissions(data, fromString("rwxrwxrwx")));
         Path symlinkedData = createTempDir("symlink-data");
         Files.delete(symlinkedData); // delete so we can replace it with a symlink
         Files.createSymbolicLink(symlinkedData, data);
