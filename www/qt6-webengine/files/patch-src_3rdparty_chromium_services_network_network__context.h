--- src/3rdparty/chromium/services/network/network_context.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/services/network/network_context.h
@@ -705,7 +705,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkContext
    public:
     explicit NetworkContextHttpAuthPreferences(NetworkService* network_service);
     ~NetworkContextHttpAuthPreferences() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool AllowGssapiLibraryLoad() const override;
 #endif  // BUILDFLAG(IS_LINUX)
    private:
