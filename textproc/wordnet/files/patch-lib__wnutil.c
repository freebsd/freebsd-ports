--- lib/wnutil.c	Fri May  6 13:17:39 2005
+++ lib/wnutil.c	Mon Mar 16 22:52:04 2020
@@ -15,5 +15,6 @@
 #ifdef __unix__
 #ifndef __MACH__
-#include <malloc.h>
+#include <stdlib.h>
+#include <stdint.h>
 #endif
 #endif
@@ -25,5 +25,5 @@
 #include "wn.h"
 
-static int do_init();
+static int do_init(void);
 
 static char msgbuf[256];	/* buffer for constructing error messages */
@@ -37,5 +37,5 @@
 /* Initialization functions */
 
-static void closefps();
+static void closefps(void);
 
 int wninit(void)
@@ -46,7 +46,6 @@
 
     if (!done) {
-	if (env = getenv("WNDBVERSION")) {
-	    wnrelease = strdup(env);	/* set release */
-	    assert(wnrelease);
+	if ((env = getenv("WNDBVERSION"))) {
+	    wnrelease = env;	/* set release */
 	}
 	openerr = do_init();
@@ -68,7 +67,6 @@
     closefps();
 
-    if (env = getenv("WNDBVERSION")) {
-	wnrelease = strdup(env);	/* set release */
-	assert(wnrelease);
+    if ((env = getenv("WNDBVERSION"))) {
+	wnrelease = env;	/* set release */
     openerr = do_init();

@@ -90,8 +89,12 @@
     if (OpenDB) {
 	for (i = 1; i < NUMPARTS + 1; i++) {
-	    if (datafps[i] != NULL)
-		fclose(datafps[i]); datafps[i] = NULL;
-	    if (indexfps[i] != NULL)
-		fclose(indexfps[i]); indexfps[i] = NULL;
+	    if (datafps[i] != NULL) {
+		fclose(datafps[i]);
+		datafps[i] = NULL;
+	    }
+	    if (indexfps[i] != NULL) {
+		fclose(indexfps[i]);
+		indexfps[i] = NULL;
+	    }
 	}
 	if (sensefp != NULL) {
@@ -248,4 +246,20 @@
 }
 
+char *strtolower2(const char *from, char *to)
+{
+
+    char *t = to;
+
+    do {
+	if(*from >= 'A' && *from <= 'Z')
+	    *t = *from++ + 32;
+	else if(*from == '(')
+	    *t = '\0';
+	else
+	    *t = *from++;
+    } while (*t++);
+    return(to);
+}
+
 /* Convert string passed to lower case */
 
@@ -276,11 +290,24 @@
 /* Return pointer code for pointer type characer passed. */
 
-int getptrtype(char *ptrstr)
+unsigned short
+getptrtype(const char *ptrstr, char **end)
 {
-    register int i;
+    unsigned short i;
+    const char *ptype, *pstr;
     for(i = 1; i <= MAXPTR; i++) {
-	if(!strcmp(ptrstr, ptrtyp[i]))
+	ptype = ptrtyp[i];
+	pstr = ptrstr;
+	while (*pstr == *ptype && *ptype) {
+	    pstr++;
+	    ptype++;
+	}
+	if (*ptype == '\0' &&
+	    (*pstr == '\n' || *pstr == ' ' || *pstr == '\0')) {
+	    if (end)
+		*end = __DECONST(char *, pstr);
 	    return(i);
+	}
     }
+    fprintf(stderr, "Could not find the type of %s\n", ptrstr);
     return(0);
 }
@@ -288,5 +315,6 @@
 /* Return part of speech code for string passed */
 
-int getpos(char *s)
+int
+getpos(const char *s)
 {
     switch (*s) {
@@ -310,5 +338,6 @@
 /* Return synset type code for string passed. */
 
-int getsstype(char *s)
+int
+getsstype(const char *s)
 {
     switch (*s) {
@@ -332,5 +361,6 @@
 /* Pass in string for POS, return corresponding integer value */
 
-int StrToPos(char *str)
+int
+StrToPos(const char *str)
 {
     if (!strcmp(str, "noun"))
@@ -389,5 +419,6 @@
 /* Return synset for sense key passed. */
 
-SynsetPtr GetSynsetForSense(char *sensekey)
+SynsetPtr
+GetSynsetForSense(const char *sensekey)
 {
     long offset;
@@ -405,7 +436,8 @@
 /* Find offset of sense key in data file */
 
-long GetDataOffset(char *sensekey)
+long
+GetDataOffset(const char *sensekey)
 {
-    char *line;
+    const char *line;
 
     /* Pass in encoded sense string, return byte offset of corresponding
@@ -426,5 +458,6 @@
 /* Find polysemy count for sense key passed. */
 
-int GetPolyCount(char *sensekey)
+int
+GetPolyCount(const char *sensekey)
 {
     IndexPtr idx;
@@ -443,5 +476,6 @@
 
 /* Return word part of sense key */
-char *GetWORD(char *sensekey)
+const char *
+GetWORD(const char *sensekey)
 {
     static char word[100];
@@ -457,5 +491,6 @@
 /* Return POS code for sense key passed. */
 
-int GetPOS(char *sensekey)
+int
+GetPOS(const char *sensekey)
 {
     int pos;
@@ -470,5 +505,6 @@
 /* Reconstruct synset from synset pointer and return ptr to buffer */
 
-char *FmtSynset(SynsetPtr synptr, int defn)
+const char *
+FmtSynset(SynsetPtr synptr, int defn)
 {
     int i;
@@ -542,27 +578,8 @@
 }
 
-/* Search for string and/or baseform of word in database and return
-   index structure for word if found in database. */
-
-IndexPtr GetValidIndexPointer(char *word, int pos)
-{
-    IndexPtr idx;
-    char *morphword;
-
-    idx = getindex(word, pos);
-
-    if (idx == NULL) {
-	if ((morphword = morphstr(word, pos)) != NULL)
-	    while (morphword) {
-		if ((idx = getindex(morphword, pos)) != NULL) break;
-		morphword = morphstr(NULL, pos);
-	    }
-    }
-    return (idx);
-}
-
 /* Return sense number in database for word and lexsn passed. */
 
-int GetWNSense(char *word, char *lexsn)
+int
+GetWNSense(const char *word, const char *lexsn)
 {
     SnsIndexPtr snsidx;
@@ -578,7 +595,8 @@
 /* Return parsed sense index entry for sense key passed. */
 
-SnsIndexPtr GetSenseIndex(char *sensekey)
+SnsIndexPtr
+GetSenseIndex(const char *sensekey)
 {
-    char *line;
+    const char *line;
     char buf[256], loc[9];
     SnsIndexPtr snsidx = NULL;
@@ -608,5 +626,6 @@
 int GetTagcnt(IndexPtr idx, int sense) 
 {
-    char *sensekey, *line;
+    char *sensekey;
+    const char *line;
     char buf[256];
     int snum, cnt = 0;
@@ -632,10 +651,11 @@
 }
 
-char *GetOffsetForKey(unsigned int key)
+const char *
+GetOffsetForKey(unsigned int key)
 {
     unsigned int rkey;
     char ckey[7];
     static char loc[11] = "";
-    char *line;
+    const char *line;
     char searchdir[256], tmpbuf[256];
 
@@ -657,10 +677,10 @@
 }
 
-
-unsigned int GetKeyForOffset(char *loc)
+unsigned int
+GetKeyForOffset(const char *loc)
 {
     unsigned int key;
     char rloc[11] = "";
-    char *line;
+    const char *line;
     char searchdir[256], tmpbuf[256];
 
@@ -681,8 +701,9 @@
 }
 
-char *SetSearchdir()
+const char *
+SetSearchdir()
 {
-    static char searchdir[256];
-    char *env;
+    char *searchdir;
+    const char *env;
 
     /* Find base directory for database.  If set, use WNSEARCHDIR.
@@ -690,14 +711,17 @@
 
     if ((env = getenv("WNSEARCHDIR")) != NULL)
-	strcpy(searchdir, env);
-    else if ((env = getenv("WNHOME")) != NULL)
+	return(env);
+    else if ((env = getenv("WNHOME")) != NULL) {
+	searchdir = malloc(strlen(env) + sizeof(DICTDIR));
 	sprintf(searchdir, "%s%s", env, DICTDIR);
-    else
-	strcpy(searchdir, DEFAULTPATH);
-
-    return(searchdir);
+	return(searchdir);
+    } else
+	return(DEFAULTPATH);
 }
 
-int default_display_message(char *msg)
+#ifndef __GNUC__
+#	define __unused
+#endif
+int default_display_message(const char *msg __unused)
 {
     return(-1);
@@ -727,3 +751,2 @@
    return (loc - strstr_stringstart);
 }
-
