--- libs/native/src/main/java/org/elasticsearch/nativeaccess/NativeAccessHolder.java.orig	2026-10-28 21:29:53 UTC
+++ libs/native/src/main/java/org/elasticsearch/nativeaccess/NativeAccessHolder.java
@@ -31,6 +31,8 @@ class NativeAccessHolder {
                 inst = new MacNativeAccess(libProvider);
             } else if (os.startsWith("Windows")) {
                 inst = new WindowsNativeAccess(libProvider);
+            } else if (os.startsWith("FreeBSD")) {
+                inst = new FreebsdNativeAccess(libProvider);
             } else {
                 logger.warn("Unsupported OS [" + os + "]. Native methods will be disabled.");
             }
