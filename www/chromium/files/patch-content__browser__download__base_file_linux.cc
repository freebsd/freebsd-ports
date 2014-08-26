--- ./content/browser/download/base_file_linux.cc.orig	2014-08-20 21:02:49.000000000 +0200
+++ ./content/browser/download/base_file_linux.cc	2014-08-22 15:06:25.000000000 +0200
@@ -13,7 +13,9 @@
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::FILE));
   DCHECK(!detached_);
 
+#if !defined(OS_BSD)
   AddOriginMetadataToFile(full_path_, source_url_, referrer_url_);
+#endif
   return DOWNLOAD_INTERRUPT_REASON_NONE;
 }
 
