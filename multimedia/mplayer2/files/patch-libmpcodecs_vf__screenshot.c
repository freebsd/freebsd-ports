--- libmpcodecs/vf_screenshot.c.orig	2016-11-30 00:06:27 UTC
+++ libmpcodecs/vf_screenshot.c
@@ -167,9 +167,9 @@ static int control (vf_instance_t *vf, i

 static int query_format(struct vf_instance *vf, unsigned int fmt)
 {
-    enum PixelFormat av_format = imgfmt2pixfmt(fmt);
+    enum AVPixelFormat av_format = imgfmt2pixfmt(fmt);

-    if (av_format != PIX_FMT_NONE && sws_isSupportedInput(av_format))
+    if (av_format != AV_PIX_FMT_NONE && sws_isSupportedInput(av_format))
         return vf_next_query_format(vf, fmt);
     return 0;
 }
