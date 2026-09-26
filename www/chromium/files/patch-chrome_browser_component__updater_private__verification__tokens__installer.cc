--- chrome/browser/component_updater/private_verification_tokens_installer.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/component_updater/private_verification_tokens_installer.cc
@@ -30,6 +30,10 @@ void RegisterPrivateVerificationTokensComponentIfEnabl
     return;
   }
 
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   auto installer = base::MakeRefCounted<ComponentInstaller>(
       std::make_unique<PrivateVerificationTokensInstallerPolicy>(
           base::BindRepeating(
@@ -51,6 +55,7 @@ void RegisterPrivateVerificationTokensComponentIfEnabl
               })));
 
   installer->Register(cus, base::OnceClosure());
+#endif
 }
 
 }  // namespace component_updater
