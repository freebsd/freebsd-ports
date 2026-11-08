--- qa/packaging/src/test/java/org/elasticsearch/packaging/util/Platforms.java.orig	2026-10-28 20:24:18 UTC
+++ qa/packaging/src/test/java/org/elasticsearch/packaging/util/Platforms.java
@@ -18,6 +18,7 @@ public class Platforms {
     public static final boolean LINUX = OS_NAME.startsWith("Linux");
     public static final boolean WINDOWS = OS_NAME.startsWith("Windows");
     public static final boolean DARWIN = OS_NAME.startsWith("Mac OS X");
+    public static final boolean FREEBSD = OS_NAME.startsWith("FreeBSD");
     public static final PlatformAction NO_ACTION = () -> {};
 
     public static String getOsRelease() {
@@ -76,6 +77,12 @@ public class Platforms {
 
     public static void onDPKG(PlatformAction action) throws Exception {
         if (isDPKG()) {
+            action.run();
+        }
+    }
+
+    public static void onFreeBSD(PlatformAction action) throws Exception {
+        if (FREEBSD) {
             action.run();
         }
     }
