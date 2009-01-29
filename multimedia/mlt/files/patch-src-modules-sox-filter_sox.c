--- src/modules/sox/filter_sox.c.orig	2008-12-20 13:29:19.000000000 +0100
+++ src/modules/sox/filter_sox.c	2008-12-20 13:29:28.000000000 +0100
@@ -35,7 +35,7 @@
 #	define ST_SUCCESS SOX_SUCCESS
 #	define st_sample_t sox_sample_t
 #	define eff_t sox_effect_t*
-#	define st_size_t sox_size_t
+#	define st_size_t size_t
 #	define ST_LIB_VERSION_CODE SOX_LIB_VERSION_CODE
 #	define ST_LIB_VERSION SOX_LIB_VERSION
 #	define ST_SIGNED_WORD_TO_SAMPLE(d,clips) SOX_SIGNED_16BIT_TO_SAMPLE(d,clips)
