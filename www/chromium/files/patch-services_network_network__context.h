--- services/network/network_context.h.orig	2024-01-30 07:53:34 UTC
+++ services/network/network_context.h
@@ -674,7 +674,7 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) NetworkContext
    public:
     explicit NetworkContextHttpAuthPreferences(NetworkService* network_service);
     ~NetworkContextHttpAuthPreferences() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool AllowGssapiLibraryLoad() const override;
 #endif  // BUILDFLAG(IS_LINUX)
    private:
