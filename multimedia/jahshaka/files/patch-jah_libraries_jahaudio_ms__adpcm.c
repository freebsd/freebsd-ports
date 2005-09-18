--- jah/libraries/jahaudio/ms_adpcm.c.orig
+++ jah/libraries/jahaudio/ms_adpcm.c
@@ -43,7 +43,7 @@
 	sf_count_t			samplecount ;
 	short			*samples ;
 	unsigned char	*block ;
-	unsigned short	dummydata [] ; /* ISO C99 struct hack */
+	unsigned short	*dummydata ; /* ISO C99 struct hack */
 } MSADPCM_PRIVATE ;
 
 /*============================================================================================
