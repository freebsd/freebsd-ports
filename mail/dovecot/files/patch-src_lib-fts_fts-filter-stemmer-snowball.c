--- src/lib-fts/fts-filter-stemmer-snowball.c.orig
+++ src/lib-fts/fts-filter-stemmer-snowball.c
@@ -6,7 +6,7 @@
 
 #ifdef HAVE_FTS_STEMMER
 
-#include <libstemmer.h>
+#include <CLucene/snowball/libstemmer.h>
 
 struct fts_filter_stemmer_snowball {
 	struct fts_filter filter;
