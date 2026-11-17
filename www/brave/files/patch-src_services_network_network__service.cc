--- src/services/network/network_service.cc.orig	2026-10-18 18:43:23 UTC
+++ src/services/network/network_service.cc
@@ -108,7 +108,7 @@
 #include "third_party/boringssl/src/include/openssl/cpu.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "services/network/network_change_notifier_passive_factory.h"
 #endif
 
@@ -1066,7 +1066,7 @@ void NetworkService::SetExplicitlyAllowe
   net::SetExplicitlyAllowedPorts(ports);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NetworkService::SetGssapiLibraryLoadObserver(
     mojo::PendingRemote<mojom::GssapiLibraryLoadObserver>
         gssapi_library_load_observer) {
@@ -1209,7 +1209,7 @@ NetworkService::CreateHttpAuthHandlerFac
   );
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void NetworkService::OnBeforeGssapiLibraryLoad() {
   if (gssapi_library_load_observer_.is_bound()) {
     gssapi_library_load_observer_->OnBeforeGssapiLibraryLoad();
