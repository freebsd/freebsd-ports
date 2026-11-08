--- libs/entitlement/src/main/java/org/elasticsearch/entitlement/runtime/policy/Platform.java.orig	2026-10-28 21:29:53 UTC
+++ libs/entitlement/src/main/java/org/elasticsearch/entitlement/runtime/policy/Platform.java
@@ -12,7 +12,8 @@ public enum Platform {
 public enum Platform {
     LINUX,
     MACOS,
-    WINDOWS;
+    WINDOWS,
+    FREEBSD;
 
     private static final Platform current = findCurrent();
 
@@ -24,6 +25,8 @@ public enum Platform {
             return MACOS;
         } else if (os.startsWith("Windows")) {
             return WINDOWS;
+        } else if (os.startsWith("FreeBSD")) {
+            return FREEBSD;
         } else {
             throw new AssertionError("Unsupported platform [" + os + "]");
         }
