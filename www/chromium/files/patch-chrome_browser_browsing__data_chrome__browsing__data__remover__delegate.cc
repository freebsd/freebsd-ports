--- chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc.orig	2021-07-19 18:45:08 UTC
+++ chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc
@@ -637,7 +637,9 @@ void ChromeBrowsingDataRemoverDelegate::RemoveEmbedder
     }
 #endif
 
+#if !defined(OS_BSD)
     CreateCrashUploadList()->Clear(delete_begin_, delete_end_);
+#endif
 
     FindBarStateFactory::GetForBrowserContext(profile_)->SetLastSearchText(
         std::u16string());
