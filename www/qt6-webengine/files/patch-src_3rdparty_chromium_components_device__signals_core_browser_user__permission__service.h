--- src/3rdparty/chromium/components/device_signals/core/browser/user_permission_service.h.orig	2023-07-16 15:47:57 UTC
+++ src/3rdparty/chromium/components/device_signals/core/browser/user_permission_service.h
@@ -57,7 +57,7 @@ class UserPermissionService : public KeyedService {
   // missing.
   virtual bool ShouldCollectConsent() const = 0;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Will verify whether context-aware signals can be collected
   // on behalf of the user represented by `user_context`. Returns `kGranted` if
   // collection is allowed.
