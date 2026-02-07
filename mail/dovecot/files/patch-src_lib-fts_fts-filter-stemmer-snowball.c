--- src/lib-fts/fts-filter-stemmer-snowball.c.orig	2020-08-12 12:20:41 UTC
+++ src/lib-fts/fts-filter-stemmer-snowball.c
@@ -6,7 +6,7 @@
 
 #ifdef HAVE_FTS_STEMMER
 
-#include <libstemmer.h>
+#include <CLucene/snowball/libstemmer.h>
 
 struct fts_filter_stemmer_snowball {
 	struct fts_filter filter;
