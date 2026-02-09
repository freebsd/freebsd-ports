--- device/fido/public/features.h.orig	2026-02-11 09:05:39 UTC
+++ device/fido/public/features.h
@@ -13,7 +13,7 @@
 namespace device {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the Passkey Unlock Manager.
 COMPONENT_EXPORT(FIDO_PUBLIC)
 BASE_DECLARE_FEATURE(kPasskeyUnlockManager);
