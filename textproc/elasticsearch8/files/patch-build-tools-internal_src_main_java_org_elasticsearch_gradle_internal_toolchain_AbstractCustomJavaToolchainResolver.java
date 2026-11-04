--- build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/toolchain/AbstractCustomJavaToolchainResolver.java.orig	2026-10-28 21:29:53 UTC
+++ build-tools-internal/src/main/java/org/elasticsearch/gradle/internal/toolchain/AbstractCustomJavaToolchainResolver.java
@@ -25,6 +25,7 @@ abstract class AbstractCustomJavaToolchainResolver imp
             case MAC_OS -> (v == null || v.equals(JvmVendorSpec.ADOPTIUM) == false) ? "macos" : "mac";
             case LINUX -> "linux";
             case WINDOWS -> "windows";
+            case FREE_BSD -> "freebsd";
             default -> throw new UnsupportedOperationException("Operating system " + operatingSystem);
         };
     }
