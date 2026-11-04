--- build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/toolchain/OracleOpenJdkToolchainResolver.java.orig	2026-10-28 21:29:53 UTC
+++ build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/toolchain/OracleOpenJdkToolchainResolver.java
@@ -61,7 +61,8 @@ public abstract class OracleOpenJdkToolchainResolver e
     private static final List<OperatingSystem> supportedOperatingSystems = List.of(
         OperatingSystem.MAC_OS,
         OperatingSystem.LINUX,
-        OperatingSystem.WINDOWS
+        OperatingSystem.WINDOWS,
+        OperatingSystem.FREE_BSD
     );
 
     // package private so it can be replaced by tests
