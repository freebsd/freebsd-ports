--- libs/foreign-library/src/main/java/org/elasticsearch/foreign/Platform.java.orig	2026-10-28 21:58:41 UTC
+++ libs/foreign-library/src/main/java/org/elasticsearch/foreign/Platform.java
@@ -19,6 +19,7 @@ public enum Platform {
     LINUX_AARCH64,
     DARWIN_X64,
     DARWIN_AARCH64,
+    FREEBSD_X64,
     WINDOWS_X64;
 
     /**
@@ -48,8 +49,9 @@ public enum Platform {
         boolean isWindows = osName.startsWith("Windows");
         boolean isLinux = osName.startsWith("Linux");
         boolean isDarwin = osName.startsWith("Mac OS");
+        boolean isFreeBSD = osName.startsWith("FreeBSD");
 
-        if (isLinux == false && isDarwin == false && isWindows == false) {
+        if (isLinux == false && isDarwin == false && isWindows == false && isFreeBSD == false) {
             throw new IllegalStateException("Unrecognized OS: " + osName);
         }
 
@@ -64,6 +66,7 @@ public enum Platform {
         if (isLinux && isAarch64) return LINUX_AARCH64;
         if (isDarwin && isX64) return DARWIN_X64;
         if (isDarwin && isAarch64) return DARWIN_AARCH64;
+        if (isFreeBSD && isX64) return FREEBSD_X64;
         if (isWindows && isX64) return WINDOWS_X64;
 
         // e.g. Windows aarch64 is not a supported Elasticsearch platform
