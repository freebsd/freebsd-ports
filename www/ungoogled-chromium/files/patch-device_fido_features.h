--- device/fido/features.h.orig	2025-12-06 13:30:52 UTC
+++ device/fido/features.h
@@ -13,7 +13,7 @@
 namespace device {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Allows the passkey unlock error UI to be shown.
 COMPONENT_EXPORT(DEVICE_FIDO)
 BASE_DECLARE_FEATURE(kPasskeyUnlockErrorUi);
