--- jah/libraries/jahaudio/ima_adpcm.c.orig
+++ jah/libraries/jahaudio/ima_adpcm.c
@@ -36,7 +36,7 @@
 	int				stepindx [2] ;
 	unsigned char	*block ;
 	short			*samples ;
-	unsigned short	data	[] ; /* ISO C99 struct hack */
+	unsigned short	*data ; /* ISO C99 struct hack */
 } IMA_ADPCM_PRIVATE ;
 
 /*============================================================================================
