--- chrome/browser/ui/url_identity.cc.orig	2025-11-01 06:40:37 UTC
+++ chrome/browser/ui/url_identity.cc
@@ -17,7 +17,7 @@
 #include "url/gurl.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -97,7 +97,7 @@ std::optional<webapps::AppId> GetIsolatedWebAppIdFromU
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 UrlIdentity CreateIsolatedWebAppIdentityFromUrl(Profile* profile,
                                                 const GURL& url,
                                                 const FormatOptions& options) {
@@ -155,7 +155,7 @@ UrlIdentity UrlIdentity::CreateFromUrl(Profile* profil
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (url.SchemeIs(webapps::kIsolatedAppScheme)) {
     DCHECK(allowed_types.Has(Type::kIsolatedWebApp));
     return CreateIsolatedWebAppIdentityFromUrl(profile, url, options);
