--- regexp.c~	Fri Nov 25 02:38:35 2005
+++ regexp.c	Tue Jan 24 12:39:04 2006
@@ -148,6 +148,7 @@
 #ifdef HAVE_PCRE
 	const char *er_ptr;
 	int erroffset;
+	pcre *ppat;
 #else
 	regmatch_t pmat[MAXCAPTURE/3];
 	regex_t ppat_data;
@@ -197,7 +198,7 @@
 #endif /* REGEX_DEBUG */
 	
 #ifdef HAVE_PCRE
-	pcre *ppat = pcre_compile(pom, 0/*PCRE_ANCHORED*/, &er_ptr, &erroffset, NULL);
+	ppat = pcre_compile(pom, 0/*PCRE_ANCHORED*/, &er_ptr, &erroffset, NULL);
 	pcre_free(pom);
 #else /* HAVE_PCRE */
 	ppat = &ppat_data;
