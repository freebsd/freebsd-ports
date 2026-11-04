--- libs/native/src/main/java/org/elasticsearch/nativeaccess/lib/NativeLibrary.java.orig	2026-10-28 21:29:53 UTC
+++ libs/native/src/main/java/org/elasticsearch/nativeaccess/lib/NativeLibrary.java
@@ -11,4 +11,4 @@ public sealed interface NativeLibrary permits JavaLibr
 
 /** A marker interface for libraries that can be loaded by {@link org.elasticsearch.nativeaccess.lib.NativeLibraryProvider} */
 public sealed interface NativeLibrary permits JavaLibrary, PosixCLibrary, LinuxCLibrary, MacCLibrary, Kernel32Library, VectorLibrary,
-    ZstdLibrary {}
+    ZstdLibrary, FreebsdCLibrary {}
