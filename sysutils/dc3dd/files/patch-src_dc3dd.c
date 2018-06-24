--- src/dc3dd.c.orig	2012-12-02 23:29:48 UTC
+++ src/dc3dd.c
@@ -45,7 +45,7 @@
    #include <linux/types.h>
    #include "hdparm/hpa_dco.h"
    #endif
-#elif defined (__APPLE__)
+#elif defined (__APPLE__) || defined (__FreeBSD__)
    #include <sys/disk.h>
    #include <sys/ioctl.h>
 #elif defined (__CYGWIN__)
@@ -2501,6 +2501,56 @@ get_file_stats(file_t* file)
    }
 }
 
+#elif defined (__FreeBSD__)
+
+static void 
+get_file_stats(file_t* file)
+{
+   file->probed = false;
+   file->is_device = false;
+   file->is_block_device = false;
+   file->probed_sector_size = 0;
+   file->probed_size_in_sectors= 0;
+   file->probed_size_in_bytes = 0;
+
+   struct stat file_info;
+   if (fstat(file->descriptor, &file_info) == 0)
+   {
+      if (file_info.st_mode & S_IFBLK)
+      {
+         // The file is a character device or a block device. It is necessary to
+         // use ioctl to query the OS to get the data to compute the size of the 
+         // device.
+         file->is_device = true;
+         file->is_block_device = true;
+         
+         uint32_t sector_size = 0;
+         uintmax_t size_in_sectors = 0;
+         off_t size_in_bytes = 0;
+         if (ioctl(file->descriptor, DIOCGSECTORSIZE, &sector_size) >= 0 &&
+             ioctl(file->descriptor, DIOCGMEDIASIZE, &size_in_bytes) >= 0)
+         {
+            size_in_sectors = (uintmax_t)size_in_bytes / sector_size;
+            file->probed_size_in_sectors = (uintmax_t)size_in_sectors;
+            file->probed_sector_size = (uintmax_t)sector_size;
+            file->probed_size_in_bytes = file->probed_size_in_sectors * file->probed_sector_size;
+            file->probed = true;
+         }
+      }
+      else
+      {
+         // The file is a file (an image).   
+         off_t start_of_file = lseek(file->descriptor, 0 , SEEK_CUR);
+         off_t end_of_file = lseek(file->descriptor, 0, SEEK_END);
+         if (lseek(file->descriptor, start_of_file, SEEK_SET) == 0)
+         {
+            file->probed_size_in_bytes = end_of_file - start_of_file;
+            file->probed = true;
+         }
+      }
+   }
+}
+
 #endif // ifdef __LINUX__
 
 // End code copied (and modified) from md5deep helpers.c
