--- services/network/network_context.h.orig	2023-10-13 13:20:35 UTC
+++ services/network/network_context.h
@@ -667,7 +667,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkContext
    public:
     explicit NetworkContextHttpAuthPreferences(NetworkService* network_service);
     ~NetworkContextHttpAuthPreferences() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool AllowGssapiLibraryLoad() const override;
 #endif  // BUILDFLAG(IS_LINUX)
    private:
