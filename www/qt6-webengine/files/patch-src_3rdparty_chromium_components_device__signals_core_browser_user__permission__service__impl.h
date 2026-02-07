--- src/3rdparty/chromium/components/device_signals/core/browser/user_permission_service_impl.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/device_signals/core/browser/user_permission_service_impl.h
@@ -38,7 +38,7 @@ class UserPermissionServiceImpl : public UserPermissio
 
   // UserPermissionService:
   bool ShouldCollectConsent() const override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   UserPermission CanUserCollectSignals(
       const UserContext& user_context) const override;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX
