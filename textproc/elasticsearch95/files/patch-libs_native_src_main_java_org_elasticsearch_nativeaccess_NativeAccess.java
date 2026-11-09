--- libs/native/src/main/java/org/elasticsearch/nativeaccess/NativeAccess.java.orig	2026-10-28 21:58:41 UTC
+++ libs/native/src/main/java/org/elasticsearch/nativeaccess/NativeAccess.java
@@ -125,6 +125,29 @@ public interface NativeAccess {
     }
 
     /**
+     * Run the given callback if the current platform is FreeBSD.
+     * @param callback A callback consuming a FreeBSD-specific native access instance
+     */
+    static void onFreebsd(Consumer<FreebsdNativeAccess> callback) {
+        if (NativeAccessHolder.INSTANCE instanceof FreebsdNativeAccess freebsdNativeAccess) {
+            callback.accept(freebsdNativeAccess);
+        }
+    }
+
+    /**
+     * Run the given callback if the current platform is FreeBSD and return a value.
+     * @param callback A callback consuming a FreeBSD-specific native access instance and returning a value
+     * @return An optional containing the result of the callback if the platform is FreeBSD, or empty otherwise
+     */
+    static <T> Optional<T> onFreebsdReturn(Function<FreebsdNativeAccess, T> callback) {
+        if (NativeAccessHolder.INSTANCE instanceof FreebsdNativeAccess freebsdNativeAccess) {
+            return Optional.of(callback.apply(freebsdNativeAccess));
+        } else {
+            return Optional.empty();
+        }
+    }
+
+    /**
      * Determine whether this JVM is running as the root user.
      *
      * @return true if running as root, or false if unsure
