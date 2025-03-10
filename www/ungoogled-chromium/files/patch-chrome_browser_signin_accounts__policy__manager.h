--- chrome/browser/signin/accounts_policy_manager.h.orig	2025-01-25 09:34:31 UTC
+++ chrome/browser/signin/accounts_policy_manager.h
@@ -13,7 +13,7 @@
 #include "components/signin/public/base/signin_metrics.h"
 #include "components/signin/public/identity_manager/identity_manager.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/scoped_observation.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -64,7 +64,7 @@ class AccountsPolicyManager : public KeyedService,
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void RemoveUnallowedAccounts();
 
   // IdentityManager::Observer implementation.
@@ -82,7 +82,7 @@ class AccountsPolicyManager : public KeyedService,
   bool hide_ui_for_testing_ = false;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<signin::IdentityManager,
                           signin::IdentityManager::Observer>
       identity_manager_observation_{this};
