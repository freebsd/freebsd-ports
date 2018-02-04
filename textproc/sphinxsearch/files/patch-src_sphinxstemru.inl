--- src/sphinxstemru.inl.orig	2018-02-03 14:10:20 UTC
+++ src/sphinxstemru.inl
@@ -413,7 +413,7 @@ STEM_RU_FUNC_I(ru_noun)
 
 static int LOC_PREFIX(stem_ru_adjectival) ( LOC_CHAR_TYPE * word, int len )
 {
-	register int i = LOC_PREFIX(stem_ru_adj_i) ( word, len );
+	int i = LOC_PREFIX(stem_ru_adj_i) ( word, len );
 	if ( i )
 		i += LOC_PREFIX(stem_ru_part_i) ( word, len-i );
 	return i;
@@ -422,7 +422,7 @@ static int LOC_PREFIX(stem_ru_adjectival) ( LOC_CHAR_T
 
 static int LOC_PREFIX(stem_ru_verb_ov) ( LOC_CHAR_TYPE * word, int len )
 {
-	register int i = LOC_PREFIX(stem_ru_verb_i) ( word, len );
+	int i = LOC_PREFIX(stem_ru_verb_i) ( word, len );
 	if ( i && (len>=i+2) && word[len-i-2] == RUS::O && word[len-i-1] == RUS::V )
 		return i+2;
 	return i;
