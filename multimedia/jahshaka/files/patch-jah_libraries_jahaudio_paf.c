--- jah/libraries/jahaudio/paf.c.orig
+++ jah/libraries/jahaudio/paf.c
@@ -64,7 +64,7 @@
 	sf_count_t		sample_count ;
 	int				*samples ;
 	unsigned char	*block ;
-	int				data [] ; /* ISO C99 struct hack */
+	int				*data ; /* ISO C99 struct hack */
 } PAF24_PRIVATE ;
 
 /*------------------------------------------------------------------------------
