--- build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/distribution/BundledJdkPlatforms.java.orig	2026-10-28 20:24:18 UTC
+++ build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/distribution/BundledJdkPlatforms.java
@@ -55,6 +55,7 @@ public final class BundledJdkPlatforms {
             case "linux" -> List.of("x64", "aarch64");
             case "darwin" -> bundledJdkMajor < FIRST_MAJOR_WITHOUT_DARWIN_X64 ? List.of("x64", "aarch64") : List.of("aarch64");
             case "windows" -> List.of("x64");
+            case "freebsd" -> List.of("x64");
             default -> throw new IllegalArgumentException("Unknown platform [" + platform + "]");
         };
     }
