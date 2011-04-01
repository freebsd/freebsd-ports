--- ./chrome/browser/sync/syncable/directory_backing_store.cc.orig	2010-12-16 02:11:54.000000000 +0100
+++ ./chrome/browser/sync/syncable/directory_backing_store.cc	2010-12-20 20:15:08.000000000 +0100
@@ -304,13 +304,13 @@
 #else
   UMA_HISTOGRAM_COUNTS_100("Sync.DirectoryOpenFailedNotWinMac", bucket);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_FREEBSD)) && !defined(OS_CHROMEOS)
   UMA_HISTOGRAM_COUNTS_100("Sync.DirectoryOpenFailedLinux", bucket);
 #elif defined(OS_CHROMEOS)
   UMA_HISTOGRAM_COUNTS_100("Sync.DirectoryOpenFailedCros", bucket);
 #else
   UMA_HISTOGRAM_COUNTS_100("Sync.DirectoryOpenFailedOther", bucket);
-#endif  // OS_LINUX && !OS_CHROMEOS
+#endif  // (OS_LINUX || OS_FREEBSD) && !OS_CHROMEOS
 #endif  // OS_WIN
   return !failed_again;
 }
