--- device/fido/features.h.orig	2026-01-16 13:40:34 UTC
+++ device/fido/features.h
@@ -13,7 +13,7 @@
 namespace device {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the Passkey Unlock Manager.
 COMPONENT_EXPORT(DEVICE_FIDO)
 BASE_DECLARE_FEATURE(kPasskeyUnlockManager);
