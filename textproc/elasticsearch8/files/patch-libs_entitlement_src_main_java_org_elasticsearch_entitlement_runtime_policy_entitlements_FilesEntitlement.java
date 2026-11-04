--- libs/entitlement/src/main/java/org/elasticsearch/entitlement/runtime/policy/entitlements/FilesEntitlement.java.orig	2026-10-28 21:29:53 UTC
+++ libs/entitlement/src/main/java/org/elasticsearch/entitlement/runtime/policy/entitlements/FilesEntitlement.java
@@ -172,8 +172,10 @@ public record FilesEntitlement(List<FileData> filesDat
             return Platform.MACOS;
         } else if (platform.equals("windows")) {
             return Platform.WINDOWS;
+        } else if (platform.equals("freebsd")) {
+            return Platform.FREEBSD;
         } else {
-            throw new PolicyValidationException("invalid platform: " + platform + ", valid values: [linux, macos, windows]");
+            throw new PolicyValidationException("invalid platform: " + platform + ", valid values: [linux, macos, windows, freebsd]");
         }
     }
 
