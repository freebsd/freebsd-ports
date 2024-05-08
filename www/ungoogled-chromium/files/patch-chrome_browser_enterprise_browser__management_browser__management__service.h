--- chrome/browser/enterprise/browser_management/browser_management_service.h.orig	2024-04-23 07:42:17 UTC
+++ chrome/browser/enterprise/browser_management/browser_management_service.h
@@ -28,7 +28,7 @@ class BrowserManagementMetadata {
 
   const gfx::Image& GetManagementLogo() const;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
  private:
   void UpdateManagementLogo(Profile* profile);
   void SetManagementLogo(
