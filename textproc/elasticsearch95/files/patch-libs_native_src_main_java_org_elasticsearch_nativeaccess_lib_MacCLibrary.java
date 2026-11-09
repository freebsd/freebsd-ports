--- libs/native/src/main/java/org/elasticsearch/nativeaccess/lib/MacCLibrary.java.orig	2026-10-28 21:58:41 UTC
+++ libs/native/src/main/java/org/elasticsearch/nativeaccess/lib/MacCLibrary.java
@@ -20,7 +20,7 @@ import java.lang.foreign.MemorySegment;
  *
  * <p>Both symbols are resolved from the system/default lookup (no dylib to load).
  */
-@LibrarySpecification(unavailableOn = { Platform.LINUX_X64, Platform.LINUX_AARCH64, Platform.WINDOWS_X64 })
+@LibrarySpecification(unavailableOn = { Platform.LINUX_X64, Platform.LINUX_AARCH64, Platform.FREEBSD_X64, Platform.WINDOWS_X64 })
 public interface MacCLibrary {
 
     /**
