--- src/3rdparty/chromium/components/password_manager/core/browser/stub_password_manager_client.h.orig	2024-09-30 07:45:04 UTC
+++ src/3rdparty/chromium/components/password_manager/core/browser/stub_password_manager_client.h
@@ -75,7 +75,7 @@ class StubPasswordManagerClient : public PasswordManag
   MockPasswordFeatureManager* GetPasswordFeatureManager();
   version_info::Channel GetChannel() const override;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void OpenPasswordDetailsBubble(
       const password_manager::PasswordForm& form) override;
   std::unique_ptr<
