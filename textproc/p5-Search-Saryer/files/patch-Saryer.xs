--- Saryer.xs.orig	Mon Dec 18 13:32:42 2000
+++ Saryer.xs	Wed Sep 17 21:50:19 2003
@@ -36,11 +36,11 @@
 	char *filename
 
 	PREINIT:
-	Saryer *saryer;
+	SarySearcher *saryer;
 	SV *sv;
 
 	CODE:
-	saryer = saryer_new(filename);
+	saryer = sary_searcher_new(filename);
 	if (saryer == NULL) {
 		RETVAL = &PL_sv_undef;
 	} else {
@@ -56,22 +56,22 @@
 	IV saryer
 
 	PREINIT:
-	Saryer *ps;
+	SarySearcher *ps;
 
 	CODE:
-	ps = (Saryer *) saryer;
-	saryer_destroy(ps);
+	ps = (SarySearcher *) saryer;
+	sary_searcher_destroy(ps);
 
 void
 perl_saryer_enable_cache(saryer)
 	IV saryer
 
 	PREINIT:
-	Saryer *ps;
+	SarySearcher *ps;
 
 	CODE:
-	ps = (Saryer *) saryer;
-	saryer_enable_cache(ps);
+	ps = (SarySearcher *) saryer;
+	sary_searcher_enable_cache(ps);
 
 SV *
 perl_saryer_search(saryer, pat)
@@ -79,12 +79,12 @@
 	char *pat
 
 	PREINIT:
-	Saryer *ps;
+	SarySearcher *ps;
 	gboolean ret;
 
 	CODE:
-	ps = (Saryer *) saryer;
-	ret = saryer_search(ps, pat);
+	ps = (SarySearcher *) saryer;
+	ret = sary_searcher_search(ps, pat);
 	if (ret) {
 		RETVAL = newSVnv(1);
 	} else {
@@ -100,12 +100,12 @@
 	char *pat
 
 	PREINIT:
-	Saryer *ps;
+	SarySearcher *ps;
 	gboolean ret;
 
 	CODE:
-	ps = (Saryer *) saryer;
-	ret = saryer_icase_search(ps, pat);
+	ps = (SarySearcher *) saryer;
+	ret = sary_searcher_icase_search(ps, pat);
 	if (ret) {
 		RETVAL = newSVnv(1);
 	} else {
@@ -120,12 +120,12 @@
 	IV saryer
 
 	PREINIT:
-	Saryer *ps;
+	SarySearcher *ps;
 	char *ret;
 
 	CODE:
-	ps = (Saryer *) saryer;
-	ret = saryer_get_next_line(ps);
+	ps = (SarySearcher *) saryer;
+	ret = sary_searcher_get_next_line(ps);
 	if (ret) {
 		RETVAL = newSVpv(ret, 0);
 		g_free(ret);
@@ -143,12 +143,12 @@
 	int fw
 
 	PREINIT:
-	Saryer *ps;
+	SarySearcher *ps;
 	char *ret;
 
 	CODE:
-	ps = (Saryer *) saryer;
-	ret = saryer_get_next_context_lines(ps, bw, fw);
+	ps = (SarySearcher *) saryer;
+	ret = sary_searcher_get_next_context_lines(ps, bw, fw);
 	if (ret) {
 		RETVAL = newSVpv(ret, 0);
 		g_free(ret);
@@ -166,12 +166,12 @@
 	char *etag
 
 	PREINIT:
-	Saryer *ps;
+	SarySearcher *ps;
 	char *ret;
 
 	CODE:
-	ps = (Saryer *) saryer;
-	ret = saryer_get_next_tagged_region(ps, stag, etag);
+	ps = (SarySearcher *) saryer;
+	ret = sary_searcher_get_next_tagged_region(ps, stag, etag);
 	if (ret) {
 		RETVAL = newSVpv(ret, 0);
 		g_free(ret);
@@ -187,8 +187,8 @@
 	IV saryer
 
 	PREINIT:
-	Saryer *ps;
+	SarySearcher *ps;
 
 	CODE:
-	ps = (Saryer *) saryer;
-	saryer_sort_occurrences(ps);
+	ps = (SarySearcher *) saryer;
+	sary_searcher_sort_occurrences(ps);
