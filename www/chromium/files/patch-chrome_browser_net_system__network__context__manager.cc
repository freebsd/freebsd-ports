--- chrome/browser/net/system_network_context_manager.cc.orig	2023-12-10 06:10:27 UTC
+++ chrome/browser/net/system_network_context_manager.cc
@@ -92,7 +92,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "chrome/common/chrome_paths_internal.h"
 #include "chrome/grit/branded_strings.h"
 #include "ui/base/l10n/l10n_util.h"
@@ -136,7 +136,7 @@ SystemNetworkContextManager* g_system_network_context_
 // received a failed launch for a sandboxed network service.
 bool g_previously_failed_to_launch_sandboxed_service = false;
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Whether kerberos library loading will work in the network service due to the
 // sandbox.
 bool g_network_service_will_allow_gssapi_library_load = false;
@@ -144,7 +144,7 @@ bool g_network_service_will_allow_gssapi_library_load 
 const char* kGssapiDesiredPref =
 #if BUILDFLAG(IS_CHROMEOS)
     prefs::kKerberosEnabled;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     prefs::kReceivedHttpAuthNegotiateHeader;
 #endif
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -190,7 +190,7 @@ network::mojom::HttpAuthDynamicParamsPtr CreateHttpAut
   auth_dynamic_params->basic_over_http_enabled =
       local_state->GetBoolean(prefs::kBasicAuthOverHttpEnabled);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   auth_dynamic_params->delegate_by_kdc_policy =
       local_state->GetBoolean(prefs::kAuthNegotiateDelegateByKdcPolicy);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
@@ -205,7 +205,7 @@ network::mojom::HttpAuthDynamicParamsPtr CreateHttpAut
       local_state->GetString(prefs::kAuthAndroidNegotiateAccountType);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auth_dynamic_params->allow_gssapi_library_load =
       local_state->GetBoolean(kGssapiDesiredPref);
 #endif  // BUILDFLAG(IS_CHROMEOS)
@@ -215,7 +215,7 @@ network::mojom::HttpAuthDynamicParamsPtr CreateHttpAut
 
 void OnNewHttpAuthDynamicParams(
     network::mojom::HttpAuthDynamicParamsPtr& params) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The kerberos library is incompatible with the network service sandbox, so
   // if library loading is now enabled, the network service needs to be
   // restarted. It will be restarted unsandboxed because is
@@ -257,11 +257,11 @@ NetworkSandboxState IsNetworkSandboxEnabledInternal() 
   if (g_previously_failed_to_launch_sandboxed_service) {
     return NetworkSandboxState::kDisabledBecauseOfFailedLaunch;
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* local_state = g_browser_process->local_state();
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The network service sandbox and the kerberos library are incompatible.
   // If kerberos is enabled by policy, disable the network service sandbox.
   if (g_network_service_will_allow_gssapi_library_load ||
@@ -277,7 +277,7 @@ NetworkSandboxState IsNetworkSandboxEnabledInternal() 
   }
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (local_state &&
       local_state->HasPrefPath(prefs::kNetworkServiceSandboxEnabled)) {
     return local_state->GetBoolean(prefs::kNetworkServiceSandboxEnabled)
@@ -472,7 +472,7 @@ void SystemNetworkContextManager::DeleteInstance() {
   g_system_network_context_manager = nullptr;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 SystemNetworkContextManager::GssapiLibraryLoadObserver::
     GssapiLibraryLoadObserver(SystemNetworkContextManager* owner)
     : owner_(owner) {}
@@ -530,7 +530,7 @@ SystemNetworkContextManager::SystemNetworkContextManag
   pref_change_registrar_.Add(prefs::kAllHttpAuthSchemesAllowedForOrigins,
                              auth_pref_callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   pref_change_registrar_.Add(prefs::kAuthNegotiateDelegateByKdcPolicy,
                              auth_pref_callback);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
@@ -544,7 +544,7 @@ SystemNetworkContextManager::SystemNetworkContextManag
                              auth_pref_callback);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   pref_change_registrar_.Add(kGssapiDesiredPref, auth_pref_callback);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
@@ -577,7 +577,7 @@ SystemNetworkContextManager::SystemNetworkContextManag
 #endif  // BUILDFLAG(CHROME_ROOT_STORE_POLICY_SUPPORTED)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   pref_change_registrar_.Add(
       prefs::kEnforceLocalAnchorConstraintsEnabled,
       base::BindRepeating(&SystemNetworkContextManager::
@@ -632,7 +632,7 @@ void SystemNetworkContextManager::RegisterPrefs(PrefRe
   registry->RegisterBooleanPref(prefs::kKerberosEnabled, false);
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kAuthNegotiateDelegateByKdcPolicy,
                                 false);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
@@ -661,7 +661,7 @@ void SystemNetworkContextManager::RegisterPrefs(PrefRe
   registry->RegisterBooleanPref(prefs::kChromeRootStoreEnabled, false);
 #endif  // BUILDFLAG(CHROME_ROOT_STORE_POLICY_SUPPORTED)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Note that the default value is not relevant because the pref is only
   // evaluated when it is managed.
   registry->RegisterBooleanPref(prefs::kEnforceLocalAnchorConstraintsEnabled,
@@ -670,11 +670,11 @@ void SystemNetworkContextManager::RegisterPrefs(PrefRe
 
   registry->RegisterListPref(prefs::kExplicitlyAllowedNetworkPorts);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kNetworkServiceSandboxEnabled, true);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kReceivedHttpAuthNegotiateHeader, false);
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -727,7 +727,7 @@ void SystemNetworkContextManager::OnNetworkServiceCrea
   OnNewHttpAuthDynamicParams(http_auth_dynamic_params);
   network_service->ConfigureHttpAuthPrefs(std::move(http_auth_dynamic_params));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gssapi_library_loader_observer_.Install(network_service);
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -938,7 +938,7 @@ bool SystemNetworkContextManager::IsNetworkSandboxEnab
       break;
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!enabled) {
     g_network_service_will_allow_gssapi_library_load = true;
   }
@@ -1052,7 +1052,7 @@ void SystemNetworkContextManager::UpdateChromeRootStor
 #endif  // BUILDFLAG(CHROME_ROOT_STORE_POLICY_SUPPORTED)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void SystemNetworkContextManager::UpdateEnforceLocalAnchorConstraintsEnabled() {
   const PrefService::Preference* enforce_local_anchor_constraints_enabled_pref =
       local_state_->FindPreference(
