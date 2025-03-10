--- chrome/browser/supervised_user/supervised_user_extensions_manager.h.orig	2025-01-25 09:34:31 UTC
+++ chrome/browser/supervised_user/supervised_user_extensions_manager.h
@@ -153,7 +153,7 @@ class SupervisedUserExtensionsManager : public Extensi
   // launched.
   bool ShouldBlockExtension(const std::string& extension_id) const;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Triggers an one-time migration of the present extensions as parent-approved
   // when the feature
   // `kEnableSupervisedUserSkipParentApprovalToInstallExtensions` becomes
