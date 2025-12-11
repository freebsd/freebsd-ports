--- remoting/signaling/ftl_host_device_id_provider.cc.orig	2025-12-10 15:04:57 UTC
+++ remoting/signaling/ftl_host_device_id_provider.cc
@@ -16,7 +16,7 @@ constexpr char kDeviceIdPrefix[] = "crd-win-host-";
 constexpr char kDeviceIdPrefix[] = "crd-mac-host-";
 #elif BUILDFLAG(IS_CHROMEOS)
 constexpr char kDeviceIdPrefix[] = "crd-cros-host-";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kDeviceIdPrefix[] = "crd-linux-host-";
 #else
 constexpr char kDeviceIdPrefix[] = "crd-unknown-host-";
