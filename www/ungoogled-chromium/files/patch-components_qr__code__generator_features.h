--- components/qr_code_generator/features.h.orig	2024-02-03 15:42:55 UTC
+++ components/qr_code_generator/features.h
@@ -26,7 +26,11 @@ BASE_DECLARE_FEATURE(kRustyQrCodeGeneratorFeature);
 // See https://crbug.com/1431991 for more details about the feature and the
 // Rust QR Code Generator project.
 inline bool IsRustyQrCodeGeneratorFeatureEnabled() {
+#ifdef notyet
   return base::FeatureList::IsEnabled(kRustyQrCodeGeneratorFeature);
+#else
+  return false;
+#endif
 }
 
 }  // namespace qr_code_generator
