--- src/sphinxstemen.cpp.orig	2018-02-03 10:36:47 UTC
+++ src/sphinxstemen.cpp
@@ -47,7 +47,7 @@ static unsigned char vowel_map[] =
 
 static inline int stem_en_id ( unsigned char l )
 {
-	register unsigned char * v = stem_en_doubles;
+	unsigned char * v = stem_en_doubles;
 	while ( *v && *v!=l ) v++;
 	return ( *v==l ) ? 1 : 0;
 }
