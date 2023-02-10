--- src/QrCodeDecoder.cpp.orig	2023-01-10 10:30:39 UTC
+++ src/QrCodeDecoder.cpp
@@ -60,7 +60,11 @@ void QrCodeDecoder::decodeImage(const QImage &image)
 {
 	// Advise the decoder to check for QR codes and to try decoding rotated versions of the image.
 #if ZXING_VERSION >= QT_VERSION_CHECK(1, 1, 0)
+# if ZXING_VERSION >= QT_VERSION_CHECK(1, 1, 1)
+	const auto decodeHints = DecodeHints().setFormats(BarcodeFormat::QRCode);
+# else
 	const auto decodeHints = DecodeHints().setFormats(BarcodeFormat::QR_CODE);
+# endif
 	const auto result = ReadBarcode({image.bits(), image.width(), image.height(), ZXing::ImageFormat::Lum, image.bytesPerLine()}, decodeHints);
 #else
 	const auto decodeHints =
@@ -77,7 +81,11 @@ void QrCodeDecoder::decodeImage(const QImage &image)
 	// If a QR code could be found and decoded, emit a signal with the decoded string.
 	// Otherwise, emit a signal for failed decoding.
 	if (result.isValid())
+#if ZXING_VERSION < QT_VERSION_CHECK(2, 0, 0)
 		emit decodingSucceeded(QString::fromStdString(TextUtfEncoding::ToUtf8(result.text())));
+#else
+		emit decodingSucceeded(QString::fromStdString(result.text()));
+#endif
 	else
 		emit decodingFailed();
 }
