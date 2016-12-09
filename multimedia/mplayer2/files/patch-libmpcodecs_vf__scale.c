--- libmpcodecs/vf_scale.c.orig	2013-07-09 16:33:16 UTC
+++ libmpcodecs/vf_scale.c
@@ -201,7 +201,7 @@ static int config(struct vf_instance *vf
     int round_w=0, round_h=0;
     int i;
     SwsFilter *srcFilter, *dstFilter;
-    enum PixelFormat dfmt, sfmt;
+    enum AVPixelFormat dfmt, sfmt;

     vf->priv->colorspace = (struct mp_csp_details) {0};

@@ -210,7 +210,7 @@ static int config(struct vf_instance *vf
 	return 0;
     }
     sfmt = imgfmt2pixfmt(outfmt);
-    if (outfmt == IMGFMT_RGB8 || outfmt == IMGFMT_BGR8) sfmt = PIX_FMT_PAL8;
+    if (outfmt == IMGFMT_RGB8 || outfmt == IMGFMT_BGR8) sfmt = AV_PIX_FMT_PAL8;
     dfmt = imgfmt2pixfmt(best);

     vo_flags=vf->next->query_format(vf->next,best);
@@ -319,13 +319,13 @@ static int config(struct vf_instance *vf
 	    sfmt,
 		  vf->priv->w, vf->priv->h >> vf->priv->interlaced,
 	    dfmt,
-	    int_sws_flags | get_sws_cpuflags(), srcFilter, dstFilter, vf->priv->param);
+	    int_sws_flags, srcFilter, dstFilter, vf->priv->param);
     if(vf->priv->interlaced){
         vf->priv->ctx2=sws_getContext(width, height >> 1,
 	    sfmt,
 		  vf->priv->w, vf->priv->h >> 1,
 	    dfmt,
-	    int_sws_flags | get_sws_cpuflags(), srcFilter, dstFilter, vf->priv->param);
+	    int_sws_flags, srcFilter, dstFilter, vf->priv->param);
     }
     if(!vf->priv->ctx){
 	// error...
@@ -612,7 +612,7 @@ error_out:
 //  supported Input formats: YV12, I420, IYUV, YUY2, UYVY, BGR32, BGR24, BGR16, BGR15, RGB32, RGB24, Y8, Y800

 static int query_format(struct vf_instance *vf, unsigned int fmt){
-    if (!IMGFMT_IS_HWACCEL(fmt) && imgfmt2pixfmt(fmt) != PIX_FMT_NONE) {
+    if (!IMGFMT_IS_HWACCEL(fmt) && imgfmt2pixfmt(fmt) != AV_PIX_FMT_NONE) {
 	unsigned int best=find_best_out(vf, fmt);
 	int flags;
 	if(!best) return 0;	 // no matching out-fmt
@@ -661,14 +661,6 @@ int sws_chr_hshift= 0;
 float sws_chr_sharpen= 0.0;
 float sws_lum_sharpen= 0.0;

-int get_sws_cpuflags(void){
-    return
-          (gCpuCaps.hasMMX   ? SWS_CPU_CAPS_MMX   : 0)
-	| (gCpuCaps.hasMMX2  ? SWS_CPU_CAPS_MMX2  : 0)
-	| (gCpuCaps.has3DNow ? SWS_CPU_CAPS_3DNOW : 0)
-        | (gCpuCaps.hasAltiVec ? SWS_CPU_CAPS_ALTIVEC : 0);
-}
-
 void sws_getFlagsAndFilterFromCmdLine(int *flags, SwsFilter **srcFilterParam, SwsFilter **dstFilterParam)
 {
 	static int firstTime=1;
@@ -717,14 +709,14 @@ static struct SwsContext *sws_getContext
 {
 	int flags;
 	SwsFilter *dstFilterParam, *srcFilterParam;
-	enum PixelFormat dfmt, sfmt;
+	enum AVPixelFormat dfmt, sfmt;

 	dfmt = imgfmt2pixfmt(dstFormat);
 	sfmt = imgfmt2pixfmt(srcFormat);
-	if (srcFormat == IMGFMT_RGB8 || srcFormat == IMGFMT_BGR8) sfmt = PIX_FMT_PAL8;
+	if (srcFormat == IMGFMT_RGB8 || srcFormat == IMGFMT_BGR8) sfmt = AV_PIX_FMT_PAL8;
 	sws_getFlagsAndFilterFromCmdLine(&flags, &srcFilterParam, &dstFilterParam);

-	return sws_getContext(srcW, srcH, sfmt, dstW, dstH, dfmt, flags | extraflags | get_sws_cpuflags(), srcFilterParam, dstFilterParam, NULL);
+	return sws_getContext(srcW, srcH, sfmt, dstW, dstH, dfmt, flags, srcFilterParam, dstFilterParam, NULL);
 }

 struct SwsContext *sws_getContextFromCmdLine(int srcW, int srcH, int srcFormat, int dstW, int dstH, int dstFormat)
