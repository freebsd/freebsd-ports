--- src/3rdparty/chromium/services/network/network_context.h.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/services/network/network_context.h
@@ -668,7 +668,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkContext
    public:
     explicit NetworkContextHttpAuthPreferences(NetworkService* network_service);
     ~NetworkContextHttpAuthPreferences() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool AllowGssapiLibraryLoad() const override;
 #endif  // BUILDFLAG(IS_LINUX)
    private:
