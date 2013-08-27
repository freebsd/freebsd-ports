--- content/browser/download/base_file_linux.cc.orig	2013-08-21 09:50:31.000000000 +0300
+++ content/browser/download/base_file_linux.cc	2013-08-21 09:51:22.000000000 +0300
@@ -13,7 +13,9 @@
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::FILE));
   DCHECK(!detached_);
 
+#if !defined(OS_BSD)
   AddOriginMetadataToFile(full_path_, source_url_, referrer_url_);
+#endif
   return DOWNLOAD_INTERRUPT_REASON_NONE;
 }
 
