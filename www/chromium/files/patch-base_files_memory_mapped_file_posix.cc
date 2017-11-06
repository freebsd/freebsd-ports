--- base/files/memory_mapped_file_posix.cc.orig	2017-08-02 18:42:44.932652000 +0200
+++ base/files/memory_mapped_file_posix.cc	2017-08-02 18:42:59.362655000 +0200
@@ -114,7 +114,7 @@
 
 #if defined(OS_ANDROID) && __ANDROID_API__ < 21
       do_manual_extension = true;
-#elif !defined(OS_MACOSX)
+#elif !defined(OS_MACOSX) && !defined(OS_BSD)
       if (posix_fallocate(file_.GetPlatformFile(), region.offset,
                           region.size) != 0) {
         DPLOG(ERROR) << "posix_fallocate " << file_.GetPlatformFile();
