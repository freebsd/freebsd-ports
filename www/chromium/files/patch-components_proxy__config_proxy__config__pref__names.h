--- components/proxy_config/proxy_config_pref_names.h.orig	2026-08-31 10:59:09 UTC
+++ components/proxy_config/proxy_config_pref_names.h
@@ -19,7 +19,7 @@ inline constexpr char kUseSharedProxies[] = "settings.
 // Preference to store the value of the "ProxyOverrideRules" policy.
 inline constexpr char kProxyOverrideRules[] = "proxy_override_rules";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Preference to store the scope (user vs machine) corresponding to the value
 // set in `kProxyOverrideRules`. It is used to handle the policy differently
 // when its source is a cloud user depending on its affiliation status and the
