--- src/components/device_signals/core/browser/user_permission_service.h.orig	2026-10-18 18:43:23 UTC
+++ src/components/device_signals/core/browser/user_permission_service.h
@@ -57,7 +57,7 @@ class UserPermissionService : public Key
   // missing.
   virtual bool ShouldCollectConsent() const = 0;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Will verify whether context-aware signals can be collected
   // on behalf of the user represented by `user_context`. Returns `kGranted` if
   // collection is allowed.
