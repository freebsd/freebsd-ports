--- utils/media-ctl/media-ctl.c.orig	2020-04-09 16:29:54 UTC
+++ utils/media-ctl/media-ctl.c
@@ -213,7 +213,7 @@ static void v4l2_subdev_print_dv_timings(const struct 
 
 		printf(" %ux%u%s%llu (%ux%u)",
 		       bt->width, bt->height, bt->interlaced ? "i" : "p",
-		       (htotal * vtotal) > 0 ? (bt->pixelclock / (htotal * vtotal)) : 0,
+		       ((htotal * vtotal) > 0 ? (bt->pixelclock / (htotal * vtotal)) : 0ULL),
 		       htotal, vtotal);
 
 		printf(" stds:");
