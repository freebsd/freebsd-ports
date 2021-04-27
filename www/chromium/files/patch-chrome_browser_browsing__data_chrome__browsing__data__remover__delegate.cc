--- chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc.orig	2021-04-23 20:21:42 UTC
+++ chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc
@@ -640,7 +640,9 @@ void ChromeBrowsingDataRemoverDelegate::RemoveEmbedder
     }
 #endif
 
+#if !defined(OS_BSD)
     CreateCrashUploadList()->Clear(delete_begin_, delete_end_);
+#endif
 
     FindBarStateFactory::GetForBrowserContext(profile_)->SetLastSearchText(
         base::string16());
