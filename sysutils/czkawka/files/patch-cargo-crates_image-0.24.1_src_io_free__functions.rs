--- cargo-crates/image-0.24.1/src/io/free_functions.rs.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/image-0.24.1/src/io/free_functions.rs
@@ -72,7 +72,8 @@ pub(crate) fn load_decoder<R: BufRead + Seek, V: Decod
         image::ImageFormat::Ico => visitor.visit_decoder(ico::IcoDecoder::new(r)?),
         #[cfg(feature = "hdr")]
         image::ImageFormat::Hdr => visitor.visit_decoder(hdr::HdrAdapter::new(BufReader::new(r))?),
-        #[cfg(feature = "openexr")]
+        #[cfg(feature = "exr")]
+        #[cfg(target_endian = "little")]
         image::ImageFormat::OpenExr => visitor.visit_decoder(openexr::OpenExrDecoder::new(r)?),
         #[cfg(feature = "pnm")]
         image::ImageFormat::Pnm => visitor.visit_decoder(pnm::PnmDecoder::new(r)?),
@@ -230,7 +231,8 @@ pub(crate) fn write_buffer_impl<W: std::io::Write + Se
         ImageOutputFormat::Tga => {
             tga::TgaEncoder::new(buffered_write).write_image(buf, width, height, color)
         }
-        #[cfg(feature = "openexr")]
+        #[cfg(feature = "exr")]
+        #[cfg(target_endian = "little")]
         ImageOutputFormat::OpenExr => {
             openexr::OpenExrEncoder::new(buffered_write).write_image(buf, width, height, color)
         }
