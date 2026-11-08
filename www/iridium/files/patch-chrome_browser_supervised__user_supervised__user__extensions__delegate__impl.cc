--- chrome/browser/supervised_user/supervised_user_extensions_delegate_impl.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/supervised_user/supervised_user_extensions_delegate_impl.cc
@@ -249,7 +249,7 @@ void SupervisedUserExtensionsDelegateImpl::RequestExte
       return;
     }
   }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   CHECK(contents.value());
   content::WebContents* web_contents = contents.value().get();
   // Always invoke the parent permission dialog.
