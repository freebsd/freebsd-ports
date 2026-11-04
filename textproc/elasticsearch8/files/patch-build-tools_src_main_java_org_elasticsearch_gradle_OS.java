--- build-tools/src/main/java/org/elasticsearch/gradle/OS.java.orig	2026-10-28 21:29:53 UTC
+++ build-tools/src/main/java/org/elasticsearch/gradle/OS.java
@@ -17,7 +17,8 @@ public enum OS {
 public enum OS {
     WINDOWS("windows"),
     MAC("darwin"),
-    LINUX("linux");
+    LINUX("linux"),
+    FREEBSD("freebsd");
 
     public final String javaOsReference;
 
@@ -37,6 +38,9 @@ public enum OS {
         if (os.startsWith("Mac")) {
             return OS.MAC;
         }
+        if (os.startsWith("FreeBSD")) {
+            return OS.FREEBSD;
+        }
         throw new IllegalStateException("Can't determine OS from: " + os);
     }
 
@@ -59,9 +63,15 @@ public enum OS {
             return this;
         }
 
+        public Conditional<T> onFreeBSD(Supplier<T> supplier) {
+            conditions.put(FREEBSD, supplier);
+            return this;
+        }
+
         public Conditional<T> onUnix(Supplier<T> supplier) {
             conditions.put(MAC, supplier);
             conditions.put(LINUX, supplier);
+            conditions.put(FREEBSD, supplier);
             return this;
         }
 
