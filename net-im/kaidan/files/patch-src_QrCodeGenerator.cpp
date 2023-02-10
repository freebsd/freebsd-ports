--- src/QrCodeGenerator.cpp.orig	2023-01-10 10:34:19 UTC
+++ src/QrCodeGenerator.cpp
@@ -33,6 +33,10 @@
 #include <QImage>
 #include <QRgb>
 
+#include <ZXing/ZXVersion.h>
+#define ZXING_VERSION \
+	QT_VERSION_CHECK(ZXING_VERSION_MAJOR, ZXING_VERSION_MINOR, ZXING_VERSION_PATCH)
+
 #include <ZXing/BarcodeFormat.h>
 #include <ZXing/MultiFormatWriter.h>
 
@@ -74,7 +78,11 @@ QImage QrCodeGenerator::generateQrCode(int edgePixelCo
 QImage QrCodeGenerator::generateQrCode(int edgePixelCount, const QString &text)
 {
 	try {
+#if ZXING_VERSION >= QT_VERSION_CHECK(1, 1, 1)
+		ZXing::MultiFormatWriter writer(ZXing::BarcodeFormat::QRCode);
+#else
 		ZXing::MultiFormatWriter writer(ZXing::BarcodeFormat::QR_CODE);
+#endif
 		const ZXing::BitMatrix &bitMatrix = writer.encode(text.toStdWString(), edgePixelCount, edgePixelCount);
 		return toImage(bitMatrix);
 	} catch (const std::invalid_argument &e) {
