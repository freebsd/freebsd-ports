--- net/http/http_auth_preferences.cc.orig	2026-08-31 10:59:09 UTC
+++ net/http/http_auth_preferences.cc
@@ -40,7 +40,7 @@ std::string HttpAuthPreferences::AuthAndroidNegotiateA
 }
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool HttpAuthPreferences::AllowGssapiLibraryLoad() const {
   return allow_gssapi_library_load_;
 }
