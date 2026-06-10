--- chrome/browser/webauthn/chrome_web_authentication_delegate.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/webauthn/chrome_web_authentication_delegate.cc
@@ -69,7 +69,7 @@
 #include "url/url_constants.h"
 #include "url/url_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/extensions/api/web_authentication_proxy/web_authentication_proxy_service.h"
 #endif
 
@@ -416,7 +416,7 @@ content::WebAuthenticationRequestProxy*
 ChromeWebAuthenticationDelegate::MaybeGetRequestProxy(
     content::BrowserContext* browser_context,
     const url::Origin& caller_origin) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The webAuthenticationProxy extension API is supported on Win/Mac/Linux.
   auto* service = extensions::WebAuthenticationProxyService::GetIfProxyAttached(
       Profile::FromBrowserContext(browser_context));
