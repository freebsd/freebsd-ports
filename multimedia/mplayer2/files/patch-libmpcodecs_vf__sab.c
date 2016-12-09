--- libmpcodecs/vf_sab.c.orig	2016-11-29 23:52:42 UTC
+++ libmpcodecs/vf_sab.c
@@ -72,7 +72,7 @@ static int allocStuff(FilterParam *f, in
 	swsF.lumH= swsF.lumV= vec;
 	swsF.chrH= swsF.chrV= NULL;
 	f->preFilterContext= sws_getContext(
-		width, height, PIX_FMT_GRAY8, width, height, PIX_FMT_GRAY8, get_sws_cpuflags()|SWS_POINT, &swsF, NULL, NULL);
+		width, height, AV_PIX_FMT_GRAY8, width, height, AV_PIX_FMT_GRAY8, SWS_POINT, &swsF, NULL, NULL);

 	sws_freeVec(vec);
 	vec = sws_getGaussianVec(f->strength, 5.0);
