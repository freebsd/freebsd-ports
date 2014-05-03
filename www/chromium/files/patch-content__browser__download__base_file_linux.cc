--- ./content/browser/download/base_file_linux.cc.orig	2014-04-24 22:35:46.000000000 +0200
+++ ./content/browser/download/base_file_linux.cc	2014-04-24 23:23:44.000000000 +0200
@@ -13,7 +13,9 @@
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::FILE));
   DCHECK(!detached_);
 
+#if !defined(OS_BSD)
   AddOriginMetadataToFile(full_path_, source_url_, referrer_url_);
+#endif
   return DOWNLOAD_INTERRUPT_REASON_NONE;
 }
 
