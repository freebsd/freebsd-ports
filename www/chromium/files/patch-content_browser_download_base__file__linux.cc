--- content/browser/download/base_file_linux.cc.orig	2016-05-24 22:54:15.000000000 -0400
+++ content/browser/download/base_file_linux.cc	2016-05-27 10:52:35.163174000 -0400
@@ -16,7 +16,9 @@
   DCHECK_CURRENTLY_ON(BrowserThread::FILE);
   DCHECK(!detached_);
 
+#if !defined(OS_BSD)
   AddOriginMetadataToFile(full_path_, source_url, referrer_url);
+#endif
   return DOWNLOAD_INTERRUPT_REASON_NONE;
 }
 
