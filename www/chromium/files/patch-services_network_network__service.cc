--- services/network/network_service.cc.orig	2025-08-07 06:57:29 UTC
+++ services/network/network_service.cc
@@ -104,11 +104,11 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
 #include "components/os_crypt/sync/key_storage_config_linux.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "services/network/network_change_notifier_passive_factory.h"
 #endif
 
@@ -1049,7 +1049,7 @@ void NetworkService::SetExplicitlyAllowedPorts(
   net::SetExplicitlyAllowedPorts(ports);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NetworkService::SetGssapiLibraryLoadObserver(
     mojo::PendingRemote<mojom::GssapiLibraryLoadObserver>
         gssapi_library_load_observer) {
@@ -1155,7 +1155,7 @@ NetworkService::CreateHttpAuthHandlerFactory(NetworkCo
   );
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NetworkService::OnBeforeGssapiLibraryLoad() {
   if (gssapi_library_load_observer_.is_bound()) {
     gssapi_library_load_observer_->OnBeforeGssapiLibraryLoad();
