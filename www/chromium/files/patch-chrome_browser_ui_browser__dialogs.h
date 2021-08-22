--- chrome/browser/ui/browser_dialogs.h.orig	2021-07-28 07:44:03 UTC
+++ chrome/browser/ui/browser_dialogs.h
@@ -121,7 +121,7 @@ void ShowWebAppInstallDialog(content::WebContents* web
                              std::unique_ptr<WebApplicationInfo> web_app_info,
                              AppInstallationAcceptanceCallback callback);
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 // Callback used to indicate whether a user has accepted the launch of a
 // web app. The boolean parameter is true when the user accepts the dialog.
 using WebAppProtocolHandlerAcceptanceCallback =
