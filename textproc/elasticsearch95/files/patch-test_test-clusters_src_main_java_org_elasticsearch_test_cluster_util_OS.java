--- test/test-clusters/src/main/java/org/elasticsearch/test/cluster/util/OS.java.orig	2026-10-28 21:29:53 UTC
+++ test/test-clusters/src/main/java/org/elasticsearch/test/cluster/util/OS.java
@@ -19,7 +19,8 @@ public enum OS {
 public enum OS {
     WINDOWS,
     MAC,
-    LINUX;
+    LINUX,
+    FREEBSD;
 
     public static OS current() {
         String os = System.getProperty("os.name", "");
@@ -32,6 +33,9 @@ public enum OS {
         if (os.startsWith("Mac")) {
             return OS.MAC;
         }
+        if (os.startsWith("FreeBSD")) {
+            return OS.FREEBSD;
+        }
         throw new IllegalStateException("Can't determine OS from: " + os);
     }
 
@@ -54,9 +58,15 @@ public enum OS {
             return this;
         }
 
+        public Conditional<T> onFreeBSD(Supplier<? extends T> supplier) {
+            conditions.put(FREEBSD, supplier);
+            return this;
+        }
+
         public Conditional<T> onUnix(Supplier<? extends T> supplier) {
             conditions.put(MAC, supplier);
             conditions.put(LINUX, supplier);
+            conditions.put(FREEBSD, supplier);
             return this;
         }
 
