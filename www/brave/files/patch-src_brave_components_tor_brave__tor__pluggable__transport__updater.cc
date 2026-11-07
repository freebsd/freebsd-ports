--- src/brave/components/tor/brave_tor_pluggable_transport_updater.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/components/tor/brave_tor_pluggable_transport_updater.cc
@@ -43,7 +43,10 @@
     "qeJ5maTLDHor8/h45B+VCw8w8jJ2e/"
     "XO6PsXziSEJUIqbMBjeeLKrrFd7C7jU92MYAUzT3FWPW4Bd270iMfyLxbMhIpMeqzJvs+"
     "wZdPOb8kowtrAtpRAQAFDX/twIDAQAB";
-#elif BUILDFLAG(IS_LINUX)
+// As in components/tor/constants.h: this chain declares the component names
+// once per platform and has no fallback, so FreeBSD needs a branch of its own
+// to declare them at all.
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr const char kComponentName[] = "Brave Pluggable Transports (Linux)";
 constexpr const char kTorPluggableTransportComponentId[] =
     "apfggiafobakjahnkchiecbomjgigkkn";
