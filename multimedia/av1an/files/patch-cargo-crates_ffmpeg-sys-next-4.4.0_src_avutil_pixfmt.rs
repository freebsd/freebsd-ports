--- cargo-crates/ffmpeg-sys-next-4.4.0/src/avutil/pixfmt.rs.orig	2022-01-03 20:02:01 UTC
+++ cargo-crates/ffmpeg-sys-next-4.4.0/src/avutil/pixfmt.rs
@@ -35,6 +35,7 @@ pub const AV_PIX_FMT_BGR555: AVPixelFormat = AV_PIX_FM
 #[cfg(target_endian = "little")]
 pub const AV_PIX_FMT_BGR444: AVPixelFormat = AV_PIX_FMT_BGR444LE;
 
+#[cfg(target_endian = "little")]
 pub const AV_PIX_FMT_YUV420P9: AVPixelFormat = AV_PIX_FMT_YUV420P9LE;
 #[cfg(target_endian = "little")]
 pub const AV_PIX_FMT_YUV422P9: AVPixelFormat = AV_PIX_FMT_YUV422P9LE;
