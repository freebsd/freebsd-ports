--- gpu/ipc/client/shared_image_interface_proxy.cc.orig	2026-11-19 12:25:27 UTC
+++ gpu/ipc/client/shared_image_interface_proxy.cc
@@ -261,7 +261,7 @@ Mailbox SharedImageInterfaceProxy::CreateSharedImage(
   // TODO(kylechar): Verify buffer_handle works for size+format.
   auto mailbox = Mailbox::Generate();
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (host_->client_type() == viz::mojom::GpuClientType::kRenderer) {
     // Only valid client from renderer on ChromeOS and Linux is VideoCapture,
     // that supposed to produce linear buffers.
