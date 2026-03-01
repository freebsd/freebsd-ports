--- app/codec/oiio/oiiodecoder.cpp.orig	2026-02-28 23:20:04 UTC
+++ app/codec/oiio/oiiodecoder.cpp
@@ -134,10 +134,20 @@ TexturePtr OIIODecoder::RetrieveVideoInternal(const Re
 
     if (p.divider == 1) {
       // Just upload straight to the buffer
+#if OIIO_VERSION >= OIIO_MAKE_VERSION(3, 0, 0)
+      // OpenImageIO 3.0+ requires subimage, miplevel, chbegin, chend parameters
+      image_->read_image(0, 0, 0, image_->spec().nchannels, oiio_pix_fmt_, buffer_.data(), OIIO::AutoStride, buffer_.linesize_bytes());
+#else
       image_->read_image(oiio_pix_fmt_, buffer_.data(), OIIO::AutoStride, buffer_.linesize_bytes());
+#endif
     } else {
       OIIO::ImageBuf buf(image_->spec());
+#if OIIO_VERSION >= OIIO_MAKE_VERSION(3, 0, 0)
+      // OpenImageIO 3.0+ requires subimage, miplevel, chbegin, chend parameters
+      image_->read_image(0, 0, 0, image_->spec().nchannels, image_->spec().format, buf.localpixels(), buf.pixel_stride(), buf.scanline_stride(), buf.z_stride());
+#else
       image_->read_image(image_->spec().format, buf.localpixels(), buf.pixel_stride(), buf.scanline_stride(), buf.z_stride());
+#endif
 
       // Roughly downsample image for divider (for some reason OIIO::ImageBufAlgo::resample failed here)
       int px_sz = vp.GetBytesPerPixel();
