--- jah/libraries/jahaudio/common.h.orig
+++ jah/libraries/jahaudio/common.h
@@ -117,7 +117,7 @@
 typedef struct
 {	unsigned int	version ;	/* version of the PEAK chunk */
 	unsigned int	timestamp ;	/* secs since 1/1/1970  */
-	PEAK_POS		peaks [] ;	/* the per channel peak info */
+	PEAK_POS	*	peaks ;	/* the per channel peak info */
 } PEAK_CHUNK ;
 
 typedef struct
