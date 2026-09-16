--- OvmfPkg/Bhyve/BhyveX64.dsc.orig	2025-08-12 17:42:44 UTC
+++ OvmfPkg/Bhyve/BhyveX64.dsc
@@ -43,8 +43,8 @@
   # Network definition
   #
   DEFINE NETWORK_TLS_ENABLE             = FALSE
-  DEFINE NETWORK_IP6_ENABLE             = FALSE
-  DEFINE NETWORK_HTTP_BOOT_ENABLE       = FALSE
+  DEFINE NETWORK_IP6_ENABLE             = TRUE
+  DEFINE NETWORK_HTTP_BOOT_ENABLE       = TRUE
   DEFINE NETWORK_ALLOW_HTTP_CONNECTIONS = TRUE
   DEFINE NETWORK_ISCSI_ENABLE           = TRUE
 
@@ -745,6 +745,20 @@
   MdeModulePkg/Universal/Acpi/S3SaveStateDxe/S3SaveStateDxe.inf
   MdeModulePkg/Universal/Acpi/BootScriptExecutorDxe/BootScriptExecutorDxe.inf
   MdeModulePkg/Universal/Acpi/BootGraphicsResourceTableDxe/BootGraphicsResourceTableDxe.inf
+
+  #
+  # EFI_RNG_PROTOCOL producer: the NetworkPkg drivers all carry a
+  # gEfiRngProtocolGuid depex, and bhyve has no virtio-rng device for
+  # VirtioRngDxe to bind to, so without this they never dispatch.
+  #
+  SecurityPkg/RandomNumberGenerator/RngDxe/RngDxe.inf
+
+  #
+  # EFI_HASH2_SERVICE_BINDING_PROTOCOL producer: TcpDxe depends on it,
+  # and without TcpDxe there is no HttpServiceBinding, so HttpBootDxe
+  # never binds. OvmfPkgX64.dsc includes this; the Bhyve DSC omitted it.
+  #
+  SecurityPkg/Hash2DxeCrypto/Hash2DxeCrypto.inf
 
   #
   # Network Support
