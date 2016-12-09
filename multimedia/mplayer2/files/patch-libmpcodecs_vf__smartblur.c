--- libmpcodecs/vf_smartblur.c.orig	2016-11-30 00:10:36 UTC
+++ libmpcodecs/vf_smartblur.c
@@ -61,7 +61,7 @@ static int allocStuff(FilterParam *f, in
 	swsF.lumH= swsF.lumV= vec;
 	swsF.chrH= swsF.chrV= NULL;
 	f->filterContext= sws_getContext(
-		width, height, PIX_FMT_GRAY8, width, height, PIX_FMT_GRAY8, SWS_BICUBIC | get_sws_cpuflags(), &swsF, NULL, NULL);
+		width, height, AV_PIX_FMT_GRAY8, width, height, AV_PIX_FMT_GRAY8, SWS_BICUBIC, &swsF, NULL, NULL);

 	sws_freeVec(vec);

