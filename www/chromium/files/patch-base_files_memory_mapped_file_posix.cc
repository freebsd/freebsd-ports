--- base/files/memory_mapped_file_posix.cc.orig	2018-02-24 16:25:08.000000000 +0100
+++ base/files/memory_mapped_file_posix.cc	2018-03-03 19:01:12.448678000 +0100
@@ -110,6 +110,8 @@
       // Only Android API>=21 supports the fallocate call. Older versions need
       // to manually extend the file by writing zeros at block intervals.
       do_manual_extension = true;
+#elif defined(OS_BSD)
+      do_manual_extension = true;
 #elif defined(OS_MACOSX)
       // MacOS doesn't support fallocate even though their new APFS filesystem
       // does support sparse files. It does, however, have the functionality
