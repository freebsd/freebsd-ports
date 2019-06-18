--- base/files/memory_mapped_file_posix.cc.orig	2019-03-11 22:00:51 UTC
+++ base/files/memory_mapped_file_posix.cc
@@ -110,6 +110,8 @@ bool MemoryMappedFile::MapFileRegionToMemory(
       // Only Android API>=21 supports the fallocate call. Older versions need
       // to manually extend the file by writing zeros at block intervals.
       do_manual_extension = true;
+#elif defined(OS_BSD)
+      do_manual_extension = true;
 #elif defined(OS_MACOSX)
       // MacOS doesn't support fallocate even though their new APFS filesystem
       // does support sparse files. It does, however, have the functionality
