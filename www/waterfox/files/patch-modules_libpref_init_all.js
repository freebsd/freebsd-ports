- ffvpx is based on ffmpeg n3.2-65-gee56777, so prefer system ffmpeg in case
  of vulnerabilites. FreeBSD package depends on ffmpeg by default, anyway.

--- modules/libpref/init/all.js.orig	2017-11-30 00:13:43 UTC
+++ modules/libpref/init/all.js
@@ -407,7 +407,11 @@ pref("media.ffmpeg.enabled", true);
 pref("media.libavcodec.allow-obsolete", false);
 #endif
 #if defined(MOZ_FFVPX)
+#if defined(MOZ_FFMPEG)
+pref("media.ffvpx.enabled", false);
+#else
 pref("media.ffvpx.enabled", true);
+#endif
 #endif
 #if defined(MOZ_FFMPEG) || defined(MOZ_FFVPX)
 pref("media.ffmpeg.low-latency.enabled", false);
