--- services/network/network_service.cc.orig	2024-03-22 14:16:19 UTC
+++ services/network/network_service.cc
@@ -97,7 +97,7 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || \
+#if ((BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)) || BUILDFLAG(IS_BSD)) || \
     BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #include "components/os_crypt/sync/key_storage_config_linux.h"
@@ -979,7 +979,7 @@ void NetworkService::SetExplicitlyAllowedPorts(
   net::SetExplicitlyAllowedPorts(ports);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NetworkService::SetGssapiLibraryLoadObserver(
     mojo::PendingRemote<mojom::GssapiLibraryLoadObserver>
         gssapi_library_load_observer) {
@@ -1061,7 +1061,7 @@ NetworkService::CreateHttpAuthHandlerFactory(NetworkCo
   );
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NetworkService::OnBeforeGssapiLibraryLoad() {
   if (gssapi_library_load_observer_.is_bound()) {
     gssapi_library_load_observer_->OnBeforeGssapiLibraryLoad();
