Comment out unused struct to avoid warnings.

--- video_freebsd.c.orig	2016-10-25 01:39:24 UTC
+++ video_freebsd.c
@@ -41,6 +41,7 @@
 
 #define array_elem(x) (sizeof(x) / sizeof((x)[0]))
 
+/*
 static const struct camparam_st {
   int min, max, range, drv_min, drv_range, def;
 } CamParams[] = {
@@ -58,6 +59,7 @@ static const struct camparam_st {
     BT848_CHROMAREGMIN, (BT848_CHROMAREGMAX - BT848_CHROMAREGMIN + 1),
     BT848_CHROMACENTER, },
 };
+*/
 
 #define BRIGHT 0
 #define CONTR  1
