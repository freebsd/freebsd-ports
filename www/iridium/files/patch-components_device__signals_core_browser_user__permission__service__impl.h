--- components/device_signals/core/browser/user_permission_service_impl.h.orig	2024-08-01 05:47:53 UTC
+++ components/device_signals/core/browser/user_permission_service_impl.h
@@ -38,7 +38,7 @@ class UserPermissionServiceImpl : public UserPermissio
 
   // UserPermissionService:
   bool ShouldCollectConsent() const override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   UserPermission CanUserCollectSignals(
       const UserContext& user_context) const override;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX
