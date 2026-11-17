--- src/net/http/http_auth_preferences.cc.orig	2026-10-18 18:43:23 UTC
+++ src/net/http/http_auth_preferences.cc
@@ -40,7 +40,7 @@ std::string HttpAuthPreferences::AuthAnd
 }
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool HttpAuthPreferences::AllowGssapiLibraryLoad() const {
   return allow_gssapi_library_load_;
 }
