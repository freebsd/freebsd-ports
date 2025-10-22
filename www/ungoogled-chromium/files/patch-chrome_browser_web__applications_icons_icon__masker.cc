--- chrome/browser/web_applications/icons/icon_masker.cc.orig	2025-10-21 16:57:35 UTC
+++ chrome/browser/web_applications/icons/icon_masker.cc
@@ -12,7 +12,7 @@
 
 namespace web_app {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 void MaskIconOnOs(SkBitmap input_bitmap, MaskedIconCallback masked_callback) {
   base::SequencedTaskRunner::GetCurrentDefault()->PostTask(
       FROM_HERE,
