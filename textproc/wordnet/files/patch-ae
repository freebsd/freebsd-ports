--- lib/search.c	2006-11-29 16:02:21.000000000 -0500
+++ lib/search.c	2014-04-01 14:50:06.000000000 -0400
@@ -17,5 +17,5 @@
 #include "wn.h"
 
-static char *Id = "$Id: search.c,v 1.166 2006/11/14 20:52:45 wn Exp $";
+__FBSDID("$Id: search.c,v 1.166 2006/11/14 20:52:45 wn Exp $");
 
 /* For adjectives, indicates synset type */
@@ -45,12 +45,12 @@
 /* Forward function declarations */
 
-static void WNOverview(char *, int);
+static void WNOverview(const char *, int);
 static void findverbgroups(IndexPtr);
-static void add_relatives(int, IndexPtr, int, int);
+static void add_relatives(int, int);
 static void free_rellist(void);
-static void printsynset(char *, SynsetPtr, char *, int, int, int, int);
-static void printantsynset(SynsetPtr, char *, int, int);
-static char *printant(int, SynsetPtr, int, char *, char *);
-static void printbuffer(char *);
+static void printsynset(const char *, SynsetPtr, const char *, int, int, int, int);
+static void printantsynset(SynsetPtr, const char *, int);
+static const char *printant(int, SynsetPtr, int, const char *, const char *);
+static void printbuffer(const char *);
 static void printsns(SynsetPtr, int);
 static void printsense(SynsetPtr, int);
@@ -62,6 +62,6 @@
 static int getsearchsense(SynsetPtr, int);
 static int depthcheck(int, SynsetPtr);
-static void interface_doevents();
-static void getexample(char *, char *);
+static void interface_doevents(void);
+static void getexample(const char *, const char *);
 static int findexample(SynsetPtr);
 
@@ -84,9 +84,10 @@
    Input word must be exact match of string in database. */
 
-IndexPtr index_lookup(char *word, int dbase)
+IndexPtr
+index_lookup(const char *word, int dbase)
 {
     IndexPtr idx = NULL;
     FILE *fp;
-    char *line;
+    const char *line;
 
     if ((fp = indexfps[dbase]) == NULL) {
@@ -111,14 +112,16 @@
  */
 
-IndexPtr parse_index(long offset, int dbase, char *line) {
+IndexPtr
+parse_index(long offset, int dbase, const char *line) {
     
     IndexPtr idx = NULL;
     char *ptrtok;
     int j;
+    int len;
 
     if ( !line )
       line = read_index( offset, indexfps[dbase] );
     
-    idx = (IndexPtr)malloc(sizeof(Index));
+    idx = malloc(sizeof(Index));
     assert(idx);
 
@@ -126,61 +129,62 @@
     idx->idxoffset = offset;
     
-    idx->wd='\0';
-    idx->pos='\0';
+    idx->wd=NULL;
+    idx->pos=NULL;
     idx->off_cnt=0;
     idx->tagged_cnt = 0;
     idx->sense_cnt=0;
-    idx->offset='\0';
+    idx->offset=NULL;
     idx->ptruse_cnt=0;
-    idx->ptruse='\0';
+    idx->ptruse=NULL;
     
     /* get the word */
-    ptrtok=strtok(line," \n");
+    ptrtok = strpbrk(line, " \n");
+    len = ptrtok - line;
     
-    idx->wd = malloc(strlen(ptrtok) + 1);
+    idx->wd = malloc(len + 1);
     assert(idx->wd);
-    strcpy(idx->wd, ptrtok);
+    memcpy(idx->wd, line, len);
+    idx->wd[len] = '\0';
+    line = ptrtok + 1;
     
     /* get the part of speech */
-    ptrtok=strtok(NULL," \n");
-    idx->pos = malloc(strlen(ptrtok) + 1);
+    ptrtok = strpbrk(line, " \n");
+    len = ptrtok - line;
+
+    idx->pos = malloc(len + 1);
     assert(idx->pos);
-    strcpy(idx->pos, ptrtok);
+    memcpy(idx->pos, line, len);
+    idx->pos[len] = '\0';
+    line = ptrtok + 1;
     
     /* get the collins count */
-    ptrtok=strtok(NULL," \n");
-    idx->sense_cnt = atoi(ptrtok);
-    
+    idx->sense_cnt = strtoul(line, &ptrtok, 10);
+ 
     /* get the number of pointers types */
-    ptrtok=strtok(NULL," \n");
-    idx->ptruse_cnt = atoi(ptrtok);
-    
+    idx->ptruse_cnt = strtoul(ptrtok + 1, &ptrtok, 10);
+
     if (idx->ptruse_cnt) {
-	idx->ptruse = (int *) malloc(idx->ptruse_cnt * (sizeof(int)));
+	idx->ptruse = malloc(idx->ptruse_cnt * (sizeof(short)));
 	assert(idx->ptruse);
 	
 	/* get the pointers types */
 	for(j=0;j < idx->ptruse_cnt; j++) {
-	    ptrtok=strtok(NULL," \n");
-	    idx->ptruse[j] = getptrtype(ptrtok);
+	    idx->ptruse[j] = getptrtype(ptrtok + 1, &ptrtok);
 	}
     }
     
     /* get the number of offsets */
-    ptrtok=strtok(NULL," \n");
-    idx->off_cnt = atoi(ptrtok);
+    idx->off_cnt = strtoul(ptrtok + 1, &ptrtok, 10);
     
     /* get the number of senses that are tagged */
-    ptrtok=strtok(NULL," \n");
-    idx->tagged_cnt = atoi(ptrtok);
-        
+    idx->tagged_cnt = strtoul(ptrtok + 1, &ptrtok, 10);
+ 
     /* make space for the offsets */
-    idx->offset = (long *) malloc(idx->off_cnt * (sizeof(long)));
+    idx->offset = malloc(idx->off_cnt * (sizeof(long)));
     assert(idx->offset);
     
     /* get the offsets */
     for(j=0;j<idx->off_cnt;j++) {
-	ptrtok=strtok(NULL," \n");
-	idx->offset[j] = atol(ptrtok);
+	idx->offset[j] = strtoul(ptrtok + 1, &ptrtok, 10);
     }
     return(idx);
@@ -191,5 +195,6 @@
    hyphens, strip hyphens and underscores, strip periods. */
 
-IndexPtr getindex(char *searchstr, int dbase)
+IndexPtr
+getindex(const char *searchstr, int dbase)
 {
     int i, j, k;
@@ -207,6 +212,8 @@
 
 	offset = 0;
-	strtolower(searchstr);
-	for (i = 0; i < MAX_FORMS; i++) {
+	strtolower2(searchstr, strings[0]);
+	searchstr = strings[0];
+	offsets[0] = 0;
+	for (i = 1; i < MAX_FORMS; i++) {
 	    strcpy(strings[i], searchstr);
 	    offsets[i] = 0;
@@ -230,9 +237,9 @@
 	   and get offsets of unique strings. */
 
-	if (strings[0][0] != NULL)
+	if (strings[0][0] != '\0')
 	    offsets[0] = index_lookup(strings[0], dbase);
 
 	for (i = 1; i < MAX_FORMS; i++)
-	    if ((strings[i][0]) != NULL && (strcmp(strings[0], strings[i])))
+	    if ((strings[i][0]) != '\0' && (strcmp(strings[0], strings[i])))
 		offsets[i] = index_lookup(strings[i], dbase);
     }
@@ -251,5 +258,6 @@
    entry in data structure. */
 
-SynsetPtr read_synset(int dbase, long boffset, char *word)
+SynsetPtr
+read_synset(int dbase, long boffset, const char *word)
 {
     FILE *fp;
@@ -270,19 +278,18 @@
    in data structure. */
 
-SynsetPtr parse_synset(FILE *fp, int dbase, char *word)
+SynsetPtr
+parse_synset(FILE *fp, int dbase, const char *word)
 {
-    static char line[LINEBUF];
-    char tbuf[SMLINEBUF];
+    char line[LINEBUF];
     char *ptrtok;
-    char *tmpptr;
     int foundpert = 0;
     char wdnum[3];
-    int i;
+    int i, len;
     SynsetPtr synptr;
-    long loc;			/* sanity check on file location */
+    unsigned long loc;		/* sanity check on file location */
 
     loc = ftell(fp);
 
-    if ((tmpptr = fgets(line, LINEBUF, fp)) == NULL)
+    if (fgets(line, LINEBUF, fp) == NULL)
 	return(NULL);
     
@@ -293,18 +300,18 @@
     synptr->sstype = DONT_KNOW;
     synptr->fnum = 0;
-    synptr->pos = '\0';
+    synptr->pos = NULL;
     synptr->wcount = 0;
-    synptr->words = '\0';
+    synptr->words = NULL;
     synptr->whichword = 0;
     synptr->ptrcount = 0;
-    synptr->ptrtyp = '\0';
-    synptr->ptroff = '\0';
-    synptr->ppos = '\0';
-    synptr->pto = '\0';
-    synptr->pfrm = '\0';
+    synptr->ptrtyp = NULL;
+    synptr->ptroff = NULL;
+    synptr->ppos = NULL;
+    synptr->pto = NULL;
+    synptr->pfrm = NULL;
     synptr->fcount = 0;
-    synptr->frmid = '\0';
-    synptr->frmto = '\0';
-    synptr->defn = '\0';
+    synptr->frmid = NULL;
+    synptr->frmto = NULL;
+    synptr->defn = NULL;
     synptr->key = 0;
     synptr->nextss = NULL;
@@ -315,13 +322,10 @@
     synptr->headsense = 0;
 
-    ptrtok = line;
-    
     /* looking at offset */
-    ptrtok = strtok(line," \n");
-    synptr->hereiam = atol(ptrtok);
+    synptr->hereiam = strtol(line, &ptrtok, 10);
 
     /* sanity check - make sure starting file offset matches first field */
     if (synptr->hereiam != loc) {
-	sprintf(msgbuf, "WordNet library error: no synset at location %d\n",
+	sprintf(msgbuf, "WordNet library error: no synset at location %lu\n",
 		loc);
 	display_message(msgbuf);
@@ -331,18 +335,20 @@
     
     /* looking at FNUM */
-    ptrtok = strtok(NULL," \n");
-    synptr->fnum = atoi(ptrtok);
+    synptr->fnum = strtol(ptrtok + 1, &ptrtok, 10);
     
     /* looking at POS */
-    ptrtok = strtok(NULL, " \n");
-    synptr->pos = malloc(strlen(ptrtok) + 1);
+    ptrtok++;
+    len = strpbrk(ptrtok, " \n") - ptrtok;
+    synptr->pos = malloc(len + 1);
     assert(synptr->pos);
-    strcpy(synptr->pos, ptrtok);
+    memcpy(synptr->pos, ptrtok, len);
+    synptr->pos[len] = '\0';
+    ptrtok += len;
     if (getsstype(synptr->pos) == SATELLITE)
 	synptr->sstype = INDIRECT_ANT;
     
     /* looking at numwords */
-    ptrtok = strtok(NULL, " \n");
-    synptr->wcount = strtol(ptrtok, NULL, 16);
+    synptr->wcount = strtol(ptrtok, &ptrtok, 16);
+    ptrtok++;
     
     synptr->words = (char **)malloc(synptr->wcount  * sizeof(char *));
@@ -354,40 +360,42 @@
     
     for (i = 0; i < synptr->wcount; i++) {
-	ptrtok = strtok(NULL, " \n");
-	synptr->words[i] = malloc(strlen(ptrtok) + 1);
+	len = strpbrk(ptrtok, " \n") - ptrtok;
+	synptr->words[i] = malloc(len + 1);
 	assert(synptr->words[i]);
-	strcpy(synptr->words[i], ptrtok);
+	memcpy(synptr->words[i], ptrtok, len);
+	synptr->words[i][len] = '\0';
 	
 	/* is this the word we're looking for? */
 	
-	if (word && !strcmp(word,strtolower(ptrtok)))
+	if (word && !strcmp(word, synptr->words[i]))
 	    synptr->whichword = i+1;
 	
-	ptrtok = strtok(NULL, " \n");
-	sscanf(ptrtok, "%x", &synptr->lexid[i]);
+	ptrtok += len;
+	synptr->lexid[i] = strtol(ptrtok, &ptrtok, 16);
+	ptrtok++;
     }
     
     /* get the pointer count */
-    ptrtok = strtok(NULL," \n");
-    synptr->ptrcount = atoi(ptrtok);
+    synptr->ptrcount = strtol(ptrtok, &ptrtok, 10);
+    ptrtok++;
 
     if (synptr->ptrcount) {
 
 	/* alloc storage for the pointers */
-	synptr->ptrtyp = (int *)malloc(synptr->ptrcount * sizeof(int));
+	synptr->ptrtyp = malloc(synptr->ptrcount * sizeof(int));
 	assert(synptr->ptrtyp);
-	synptr->ptroff = (long *)malloc(synptr->ptrcount * sizeof(long));
+	synptr->ptroff = malloc(synptr->ptrcount * sizeof(unsigned long));
 	assert(synptr->ptroff);
-	synptr->ppos = (int *)malloc(synptr->ptrcount * sizeof(int));
+	synptr->ppos = malloc(synptr->ptrcount * sizeof(int));
 	assert(synptr->ppos);
-	synptr->pto = (int *)malloc(synptr->ptrcount * sizeof(int));
+	synptr->pto = malloc(synptr->ptrcount * sizeof(short));
 	assert(synptr->pto);
-	synptr->pfrm = (int *)malloc(synptr->ptrcount * sizeof(int));
+	synptr->pfrm = malloc(synptr->ptrcount * sizeof(short));
 	assert(synptr->pfrm);
     
 	for(i = 0; i < synptr->ptrcount; i++) {
 	    /* get the pointer type */
-	    ptrtok = strtok(NULL," \n");
-	    synptr->ptrtyp[i] = getptrtype(ptrtok);
+	    synptr->ptrtyp[i] = getptrtype(ptrtok, &ptrtok);
+	    ptrtok++;
 	    /* For adjectives, set the synset type if it has a direct
 	       antonym */
@@ -400,23 +408,19 @@
 
 	    /* get the pointer offset */
-	    ptrtok = strtok(NULL," \n");
-	    synptr->ptroff[i] = atol(ptrtok);
+	    synptr->ptroff[i] = strtol(ptrtok, &ptrtok, 10);
+	    ptrtok++;
 	
 	    /* get the pointer part of speech */
-	    ptrtok = strtok(NULL, " \n");
 	    synptr->ppos[i] = getpos(ptrtok);
 	
 	    /* get the lexp to/from restrictions */
-	    ptrtok = strtok(NULL," \n");
-	
-	    tmpptr = ptrtok;
-	    strncpy(wdnum, tmpptr, 2);
+
+	    ptrtok = strpbrk(ptrtok, " \n") + 1;
+	    strncpy(wdnum, ptrtok, 2);
 	    wdnum[2] = '\0';
-	    synptr->pfrm[i] = strtol(wdnum, (char **)NULL, 16);
+	    synptr->pfrm[i] = strtoul(wdnum, NULL, 16);
 	
-	    tmpptr += 2;
-	    strncpy(wdnum, tmpptr, 2);
-	    wdnum[2] = '\0';
-	    synptr->pto[i] = strtol(wdnum, (char **)NULL, 16);
+	    synptr->pto[i] = strtoul(ptrtok + 2, &ptrtok, 16);
+	    ptrtok++; /* Something like ``0000 '' */
 	}
     }
@@ -429,23 +433,22 @@
     /* retireve optional information from verb synset */
     if(dbase == VERB) {
-	ptrtok = strtok(NULL," \n");
-	synptr->fcount = atoi(ptrtok);
-	
+	synptr->fcount = strtol(ptrtok, &ptrtok, 10);
+	ptrtok++;
 	/* allocate frame storage */
 	
-	synptr->frmid = (int *)malloc(synptr->fcount * sizeof(int));  
+	synptr->frmid = malloc(synptr->fcount * sizeof(int));  
 	assert(synptr->frmid);
-	synptr->frmto = (int *)malloc(synptr->fcount * sizeof(int));  
+	synptr->frmto = malloc(synptr->fcount * sizeof(int));  
 	assert(synptr->frmto);
 	
 	for(i=0;i<synptr->fcount;i++) {
 	    /* skip the frame pointer (+) */
-	    ptrtok = strtok(NULL," \n");
+	    ptrtok = strpbrk(ptrtok, " \n") + 1;
 	    
-	    ptrtok = strtok(NULL," \n");
-	    synptr->frmid[i] = atoi(ptrtok);
+	    synptr->frmid[i] = strtol(ptrtok, &ptrtok, 10);
+	    ptrtok++;
 	    
-	    ptrtok = strtok(NULL," \n");
-	    synptr->frmto[i] = strtol(ptrtok, NULL, 16);
+	    synptr->frmto[i] = strtol(ptrtok, &ptrtok, 16);
+	    ptrtok++;
 	}
     }
@@ -453,22 +456,38 @@
     /* get the optional definition */
     
-    ptrtok = strtok(NULL," \n");
-    if (ptrtok) {
-	ptrtok = strtok(NULL," \n");
-	sprintf(tbuf, "");
-	while (ptrtok != NULL) {
-	    strcat(tbuf,ptrtok);
-	    ptrtok = strtok(NULL, " \n");
-	    if(ptrtok)
-		strcat(tbuf," ");
-	}
-	assert((1 + strlen(tbuf)) < sizeof(tbuf));
-	synptr->defn = malloc(strlen(tbuf) + 4);
+    ptrtok = strpbrk(ptrtok, " \n") + 1;
+    if (ptrtok && *ptrtok) {
+	char *defn;
+	len = strlen(ptrtok);
+	synptr->defn = malloc(len + 2);
 	assert(synptr->defn);
-	sprintf(synptr->defn,"(%s)",tbuf);
+	synptr->defn[0] = '(';
+	for (defn = synptr->defn + 1; *ptrtok; ptrtok++) {
+		switch (*ptrtok) {
+		case '\n':
+		case ' ':
+			/* skip adjacent and initial blanks: */
+			if (defn == synptr->defn + 1 || defn[-1] == ' ')
+				continue;
+			do
+				ptrtok++;
+			while (*ptrtok == '\n' || *ptrtok == ' ');
+			if (*ptrtok == '\0')
+				break; /* out of the loop */
+			*defn++ = ' ';
+			/* FALLTHROUGH */;
+		default:
+			*defn++ = *ptrtok;
+			continue;
+		}
+		break;
+	}
+	*defn++ = ')';
+	assert(defn - synptr->defn < len + 2);
+	*defn = '\0';
     }
 
     if (keyindexfp) { 		/* we have unique keys */
-	sprintf(tmpbuf, "%c:%8.8d", partchars[dbase], synptr->hereiam);
+	sprintf(tmpbuf, "%c:%8.8ld", partchars[dbase], synptr->hereiam);
 	synptr->key = GetKeyForOffset(tmpbuf);
     }
@@ -547,5 +566,5 @@
 /* Recursive search algorithm to trace a pointer tree */
 
-static void traceptrs(SynsetPtr synptr, int ptrtyp, int dbase, int depth)
+static void traceptrs(SynsetPtr synptr, int ptyp, int dbase, int depth)
 {
     int i;
@@ -559,15 +578,15 @@
 	return;
 
-    if (ptrtyp < 0) {
-	ptrtyp = -ptrtyp;
+    if (ptyp < 0) {
+	ptyp = -ptyp;
 	extraindent = 2;
     }
     
     for (i = 0; i < synptr->ptrcount; i++) {
-	if ((ptrtyp == HYPERPTR && (synptr->ptrtyp[i] == HYPERPTR ||
+	if ((ptyp == HYPERPTR && (synptr->ptrtyp[i] == HYPERPTR ||
 				    synptr->ptrtyp[i] == INSTANCE)) ||
-	    (ptrtyp == HYPOPTR && (synptr->ptrtyp[i] == HYPOPTR ||
+	    (ptyp == HYPOPTR && (synptr->ptrtyp[i] == HYPOPTR ||
 				   synptr->ptrtyp[i] == INSTANCES)) ||
-	    ((synptr->ptrtyp[i] == ptrtyp) &&
+	    ((synptr->ptrtyp[i] == ptyp) &&
 	     ((synptr->pfrm[i] == 0) ||
 	      (synptr->pfrm[i] == synptr->whichword)))) {
@@ -634,5 +653,5 @@
 	       Otherwise, just print the synset pointed to. */
 
-	    if ((ptrtyp == PERTPTR || ptrtyp == PPLPTR) &&
+	    if ((ptyp == PERTPTR || ptyp == PPLPTR) &&
 		synptr->pto[i] != 0) {
 		sprintf(tbuf, " (Sense %d)\n",
@@ -640,5 +659,5 @@
 		printsynset(prefix, cursyn, tbuf, DEFOFF, synptr->pto[i],
 			    SKIP_ANTS, PRINT_MARKER);
-		if (ptrtyp == PPLPTR) { /* adjective pointing to verb */
+		if (ptyp == PPLPTR) { /* adjective pointing to verb */
 		    printsynset("      =>", cursyn, "\n",
 				DEFON, ALLWORDS, PRINT_ANTS, PRINT_MARKER);
@@ -656,5 +675,5 @@
 		    traceptrs(cursyn, HYPERPTR, getpos(cursyn->pos), 0);
 		}
-	    } else if (ptrtyp == ANTPTR && dbase != ADJ && synptr->pto[i] != 0) {
+	    } else if (ptyp == ANTPTR && dbase != ADJ && synptr->pto[i] != 0) {
 		sprintf(tbuf, " (Sense %d)\n",
 			cursyn->wnsns[synptr->pto[i] - 1]);
@@ -670,10 +689,10 @@
 	       printed in buffer so results can be truncated later. */
 
-	    if (ptrtyp >= ISMEMBERPTR && ptrtyp <= HASPARTPTR)
+	    if (ptyp >= ISMEMBERPTR && ptyp <= HASPARTPTR)
 		lastholomero = strlen(searchbuffer);
 
 	    if(depth) {
 		depth = depthcheck(depth, cursyn);
-		traceptrs(cursyn, ptrtyp, getpos(cursyn->pos), (depth+1));
+		traceptrs(cursyn, ptyp, getpos(cursyn->pos), (depth+1));
 
 		free_synset(cursyn);
@@ -684,5 +703,6 @@
 }
 
-static void tracecoords(SynsetPtr synptr, int ptrtyp, int dbase, int depth)
+static void
+tracecoords(SynsetPtr synptr, int ptyp, int depth)
 {
     int i;
@@ -709,9 +729,9 @@
 			SKIP_ANTS, PRINT_MARKER);
 
-	    traceptrs(cursyn, ptrtyp, getpos(cursyn->pos), depth);
+	    traceptrs(cursyn, ptyp, getpos(cursyn->pos), depth);
 	    
 	    if(depth) {
 		depth = depthcheck(depth, cursyn);
-		tracecoords(cursyn, ptrtyp, getpos(cursyn->pos), (depth+1));
+		tracecoords(cursyn, ptyp, (depth+1));
 		free_synset(cursyn);
 	    } else
@@ -721,9 +741,10 @@
 }
 
-static void traceclassif(SynsetPtr synptr, int dbase, int search)
+static void
+traceclassif(SynsetPtr synptr, int search)
 {
     int i, j, idx;
     SynsetPtr cursyn;
-    long int prlist[1024];
+    unsigned int prlist[1024];
     char head[60];
     int svwnsnsflag;
@@ -789,9 +810,12 @@
 }
 
-static void tracenomins(SynsetPtr synptr, int dbase)
+static void
+tracenomins(SynsetPtr synptr)
 {
     int i, j, idx;
     SynsetPtr cursyn;
+#ifdef FOOP
     long int prlist[1024];
+#endif
     char prefix[40], tbuf[20];
 
@@ -823,16 +847,20 @@
 			SKIP_ANTS, SKIP_MARKER);
 
+#ifdef FOOP
 	    /* only print synset once, even if more than one link */
 
 	    for (j = 0; j < idx; j++) {
-#ifdef FOOP
 		if (synptr->ptroff[i] == prlist[j]) {
 		    break;
 		}
-#endif
 	    }
+#else
+	    j = idx;
+#endif
 
 	    if (j == idx) {
+#ifdef FOOP
 		prlist[idx++] = synptr->ptroff[i];
+#endif
 		printspaces(TRACEP, 2);
 		printsynset("=> ", cursyn, "\n", DEFON, ALLWORDS,
@@ -848,5 +876,6 @@
    and PART info. */
 
-static void traceinherit(SynsetPtr synptr, int ptrbase, int dbase, int depth)
+static void
+traceinherit(SynsetPtr synptr, int ptrbase, int depth)
 {
     int i;
@@ -879,5 +908,5 @@
 	    if(depth) {
 		depth = depthcheck(depth, cursyn);
-		traceinherit(cursyn, ptrbase, getpos(cursyn->pos), (depth+1));
+		traceinherit(cursyn, ptrbase, depth + 1);
 		free_synset(cursyn);
 	    } else
@@ -890,10 +919,10 @@
 }
 
-static void partsall(SynsetPtr synptr, int ptrtyp)
+static void partsall(SynsetPtr synptr, int ptyp)
 {
     int ptrbase;
     int i, hasptr = 0;
     
-    ptrbase = (ptrtyp == HMERONYM) ? HASMEMBERPTR : ISMEMBERPTR;
+    ptrbase = (ptyp == HMERONYM) ? HASMEMBERPTR : ISMEMBERPTR;
     
     /* First, print out the MEMBER, STUFF, PART info for this synset */
@@ -912,8 +941,8 @@
        HMERONYM search only */
 	
-/*    if (hasptr && ptrtyp == HMERONYM) { */
-    if (ptrtyp == HMERONYM) {
+/*    if (hasptr && ptyp == HMERONYM) { */
+    if (ptyp == HMERONYM) {
 	lastholomero = strlen(searchbuffer);
-	traceinherit(synptr, ptrbase, NOUN, 1);
+	traceinherit(synptr, ptrbase, 1);
     }
 }
@@ -971,5 +1000,5 @@
 		    }
 		} else
-		    printantsynset(antptr, "\n", anttype, DEFON);
+		    printantsynset(antptr, "\n", DEFON);
 
 		free_synset(antptr);
@@ -984,11 +1013,13 @@
 /* Fetch the given example sentence from the example file and print it out */
 
-void getexample(char *offset, char *wd)
+static void
+getexample(const char *offset, const char *wd)
 {
-    char *line;
+    const char *line;
     char sentbuf[512];
     
     if (vsentfilefp != NULL) {
-	if (line = bin_search(offset, vsentfilefp)) {
+	line = bin_search(offset, vsentfilefp);
+	if (line) {
 	    while(*line != ' ') 
 		line++;
@@ -1005,5 +1036,6 @@
 int findexample(SynsetPtr synptr)
 {
-    char tbuf[256], *temp, *offset;
+    char tbuf[256];
+    const char *temp, *offset;
     int wdnum;
     int found = 0;
@@ -1103,17 +1135,17 @@
 }
 
-static void freq_word(IndexPtr index)
+static void freq_word(IndexPtr idx)
 {
     int familiar=0;
     int cnt;
-    static char *a_an[] = {
+    static const char *a_an[] = {
 	"", "a noun", "a verb", "an adjective", "an adverb" };
-    static char *freqcats[] = {
+    static const char *freqcats[] = {
 	"extremely rare","very rare","rare","uncommon","common",
 	"familiar","very familiar","extremely familiar"
     };
 
-    if(index) {
-	cnt = index->sense_cnt;
+    if(idx) {
+	cnt = idx->sense_cnt;
 	if (cnt == 0) familiar = 0;
 	if (cnt == 1) familiar = 1;
@@ -1127,10 +1159,11 @@
 	sprintf(tmpbuf,
 		"\n%s used as %s is %s (polysemy count = %d)\n",
-		index->wd, a_an[getpos(index->pos)], freqcats[familiar], cnt);
+		idx->wd, a_an[getpos(idx->pos)], freqcats[familiar], cnt);
 	printbuffer(tmpbuf);
     }
 }
 
-void wngrep (char *word_passed, int pos) {
+static void
+wngrep(const char *word_passed, int pos) {
    FILE *inputfile;
    char word[256];
@@ -1243,5 +1276,5 @@
 		   for (k = 0; k < idx->off_cnt; k++) {
 		       if (synset->ptroff[j] == idx->offset[k]) {
-			   add_relatives(VERB, idx, i, k);
+			   add_relatives(i, k);
 			   break;
 		       }
@@ -1253,8 +1286,9 @@
 }
 
-static void add_relatives(int pos, IndexPtr idx, int rel1, int rel2)
+static void
+add_relatives(int rel1, int rel2)
 {
     int i;
-    struct relgrp *rel, *last, *r;
+    struct relgrp *rel, *last = NULL, *r;
 
     /* If either of the new relatives are already in a relative group,
@@ -1356,5 +1390,6 @@
 */
 
-char *findtheinfo(char *searchstr, int dbase, int ptrtyp, int whichsense)
+const char *
+findtheinfo(const char *searchstr, int dbase, int ptyp, int whichsense)
 {
     SynsetPtr cursyn;
@@ -1364,5 +1399,5 @@
     char *bufstart;
     unsigned long offsets[MAXSENSE];
-    int skipit;
+    int skipit = 0;
 
     /* Initializations -
@@ -1379,5 +1414,5 @@
 	offsets[i] = 0;
 
-    switch (ptrtyp) {
+    switch (ptyp) {
     case OVERVIEW:
 	WNOverview(searchstr, dbase);
@@ -1408,6 +1443,6 @@
 
 	/* If negative search type, set flag for recursive search */
-	if (ptrtyp < 0) {
-	    ptrtyp = -ptrtyp;
+	if (ptyp < 0) {
+	    ptyp = -ptyp;
 	    depth = 1;
 	}
@@ -1445,5 +1480,5 @@
 		    	offsets[offsetcnt++] = idx->offset[sense];
 		    	cursyn = read_synset(dbase, idx->offset[sense], idx->wd);
-		    	switch(ptrtyp) {
+		    	switch(ptyp) {
 		    	case ANTPTR:
 			    if(dbase == ADJ)
@@ -1454,5 +1489,5 @@
 		   	 
 		    	case COORDS:
-			    tracecoords(cursyn, HYPOPTR, dbase, depth);
+			    tracecoords(cursyn, HYPOPTR, depth);
 			    break;
 		   	 
@@ -1487,5 +1522,5 @@
 #ifdef FOOP
 			case PPLPTR:
-			    traceptrs(cursyn, ptrtyp, dbase, depth);
+			    traceptrs(cursyn, ptyp, dbase, depth);
 			    traceptrs(cursyn, PPLPTR, dbase, depth);
 			    break;
@@ -1498,5 +1533,5 @@
 			    prflag = 1;
 		    
-			    traceptrs(cursyn, ptrtyp, dbase, depth);
+			    traceptrs(cursyn, ptyp, dbase, depth);
 		    
 			    if (dbase == ADJ) {
@@ -1522,14 +1557,14 @@
 
 			case DERIVATION:
-			    tracenomins(cursyn, dbase);
+			    tracenomins(cursyn);
 			    break;
 
 			case CLASSIFICATION:
 			case CLASS:
-			    traceclassif(cursyn, dbase, ptrtyp);
+			    traceclassif(cursyn, ptyp);
 			    break;
 
 		    	default:
-			    traceptrs(cursyn, ptrtyp, dbase, depth);
+			    traceptrs(cursyn, ptyp, dbase, depth);
 			    break;
 
@@ -1600,5 +1635,6 @@
 }
 
-SynsetPtr findtheinfo_ds(char *searchstr, int dbase, int ptrtyp, int whichsense)
+SynsetPtr
+findtheinfo_ds(char *searchstr, int dbase, int ptyp, int whichsense)
 {
     IndexPtr idx;
@@ -1616,6 +1652,6 @@
 	newsense = 1;
 	
-	if(ptrtyp < 0) {
-	    ptrtyp = -ptrtyp;
+	if(ptyp < 0) {
+	    ptyp = -ptyp;
 	    depth = 1;
 	}
@@ -1642,8 +1678,6 @@
 		newsense = 0;
 	    
-		cursyn->searchtype = ptrtyp;
-		cursyn->ptrlist = traceptrs_ds(cursyn, ptrtyp, 
-					       getpos(cursyn->pos),
-					       depth);
+		cursyn->searchtype = ptyp;
+		cursyn->ptrlist = traceptrs_ds(cursyn, ptyp, depth);
 	    
 		lastsyn = cursyn;
@@ -1656,5 +1690,5 @@
 	wnresults.numforms++;
 
-	if (ptrtyp == COORDS) {	/* clean up by removing hypernym */
+	if (ptyp == COORDS) {	/* clean up by removing hypernym */
 	    lastsyn = synlist->ptrlist;
 	    synlist->ptrlist = lastsyn->ptrlist;
@@ -1669,5 +1703,6 @@
   in linked list of data structures. */
 
-SynsetPtr traceptrs_ds(SynsetPtr synptr, int ptrtyp, int dbase, int depth)
+SynsetPtr
+traceptrs_ds(SynsetPtr synptr, int ptyp, int depth)
 {
     int i;
@@ -1693,9 +1728,9 @@
     }
 
-    if (ptrtyp == COORDS) {
+    if (ptyp == COORDS) {
 	tstptrtyp = HYPERPTR;
 	docoords = 1;
     } else {
-	tstptrtyp = ptrtyp;
+	tstptrtyp = ptyp;
 	docoords = 0;
     }
@@ -1707,5 +1742,5 @@
 	    
 	    cursyn=read_synset(synptr->ppos[i], synptr->ptroff[i], "");
-	    cursyn->searchtype = ptrtyp;
+	    cursyn->searchtype = ptyp;
 
 	    if (lastsyn)
@@ -1717,9 +1752,7 @@
 	    if(depth) {
 		depth = depthcheck(depth, cursyn);
-		cursyn->ptrlist = traceptrs_ds(cursyn, ptrtyp,
-					       getpos(cursyn->pos),
-					       (depth+1));
+		cursyn->ptrlist = traceptrs_ds(cursyn, ptyp, (depth+1));
 	    } else if (docoords) {
-		cursyn->ptrlist = traceptrs_ds(cursyn, HYPOPTR, NOUN, 0);
+		cursyn->ptrlist = traceptrs_ds(cursyn, HYPOPTR, 0);
 	    }
 	}
@@ -1728,10 +1761,12 @@
 }
 
-static void WNOverview(char *searchstr, int pos)
+static void
+WNOverview(const char *searchstr, int pos)
 {
     SynsetPtr cursyn;
     IndexPtr idx = NULL;
-    char *cpstring = searchstr, *bufstart;
-    int sense, i, offsetcnt;
+    const char *cpstring;
+    char *bufstart;
+    int sense_, i, offsetcnt;
     int svdflag, skipit;
     unsigned long offsets[MAXSENSE];
@@ -1755,19 +1790,19 @@
 	   synset with synset offset and/or lexical file information.*/
 
-	for (sense = 0; sense < idx->off_cnt; sense++) {
+	for (sense_ = 0; sense_ < idx->off_cnt; sense_++) {
 
 	    for (i = 0, skipit = 0; i < offsetcnt && !skipit; i++)
-		if (offsets[i] == idx->offset[sense])
+		if (offsets[i] == idx->offset[sense_])
 		    skipit = 1;
 
 	    if (!skipit) {
-		offsets[offsetcnt++] = idx->offset[sense];
-		cursyn = read_synset(pos, idx->offset[sense], idx->wd);
+		offsets[offsetcnt++] = idx->offset[sense_];
+		cursyn = read_synset(pos, idx->offset[sense_], idx->wd);
 		if (idx->tagged_cnt != -1 &&
-		    ((sense + 1) <= idx->tagged_cnt)) {
+		    ((sense_ + 1) <= idx->tagged_cnt)) {
 		  sprintf(tmpbuf, "%d. (%d) ",
-			  sense + 1, GetTagcnt(idx, sense + 1));
+			  sense_ + 1, GetTagcnt(idx, sense_ + 1));
 		} else {
-		  sprintf(tmpbuf, "%d. ", sense + 1);
+		  sprintf(tmpbuf, "%d. ", sense_ + 1);
 		}
 
@@ -1814,8 +1849,9 @@
 /* Do requested search on synset passed, returning output in buffer. */
 
-char *do_trace(SynsetPtr synptr, int ptrtyp, int dbase, int depth)
+const char *
+do_trace(SynsetPtr synptr, int ptyp, int dbase, int depth)
 {
     searchbuffer[0] = '\0';	/* clear output buffer */
-    traceptrs(synptr, ptrtyp, dbase, depth);
+    traceptrs(synptr, ptyp, dbase, depth);
     return(searchbuffer);
 }
@@ -1824,7 +1860,8 @@
    passed and return bit mask. */
   
-unsigned int is_defined(char *searchstr, int dbase)
+unsigned int
+is_defined(const char *searchstr, int dbase)
 {
-    IndexPtr index;
+    IndexPtr idx;
     int i;
     unsigned long retval = 0;
@@ -1834,8 +1871,8 @@
     wnresults.searchds = NULL;
 
-    while ((index = getindex(searchstr, dbase)) != NULL) {
+    while ((idx = getindex(searchstr, dbase)) != NULL) {
 	searchstr = NULL;	/* clear out for next getindex() call */
 
-	wnresults.SenseCount[wnresults.numforms] = index->off_cnt;
+	wnresults.SenseCount[wnresults.numforms] = idx->off_cnt;
 	
 	/* set bits that must be true for all words */
@@ -1846,36 +1883,36 @@
 	/* go through list of pointer characters and set appropriate bits */
 
-	for(i = 0; i < index->ptruse_cnt; i++) {
+	for(i = 0; i < idx->ptruse_cnt; i++) {
 
-	    if (index->ptruse[i] <= LASTTYPE) {
-		retval |= bit(index->ptruse[i]);
-	    } else if (index->ptruse[i] == INSTANCE) {
+	    if (idx->ptruse[i] <= LASTTYPE) {
+		retval |= bit(idx->ptruse[i]);
+	    } else if (idx->ptruse[i] == INSTANCE) {
 		retval |= bit(HYPERPTR);
-	    } else if (index->ptruse[i] == INSTANCES) {
+	    } else if (idx->ptruse[i] == INSTANCES) {
 		retval |= bit(HYPOPTR);
 	    }
 	    
-	    if (index->ptruse[i] == SIMPTR) {
+	    if (idx->ptruse[i] == SIMPTR) {
 		retval |= bit(ANTPTR);
 	    } 
 #ifdef FOOP
 
-	    if (index->ptruse[i] >= CLASSIF_START &&
-		 index->ptruse[i] <= CLASSIF_END) {
+	    if (idx->ptruse[i] >= CLASSIF_START &&
+		 idx->ptruse[i] <= CLASSIF_END) {
 		retval |= bit(CLASSIFICATION);
 	    }
 
 
-	    if (index->ptruse[i] >= CLASS_START &&
-		 index->ptruse[i] <= CLASS_END) {
+	    if (idx->ptruse[i] >= CLASS_START &&
+		 idx->ptruse[i] <= CLASS_END) {
 		retval |= bit(CLASS);
 	    }
 #endif
 
-	    if (index->ptruse[i] >= ISMEMBERPTR &&
-	       index->ptruse[i] <= ISPARTPTR)
+	    if (idx->ptruse[i] >= ISMEMBERPTR &&
+	       idx->ptruse[i] <= ISPARTPTR)
 		retval |= bit(HOLONYM);
-	    else if (index->ptruse[i] >= HASMEMBERPTR &&
-		    index->ptruse[i] <= HASPARTPTR)
+	    else if (idx->ptruse[i] >= HASMEMBERPTR &&
+		    idx->ptruse[i] <= HASPARTPTR)
 		retval |= bit(MERONYM);
 	 
@@ -1886,7 +1923,7 @@
 	    /* check for inherited holonyms and meronyms */
 
-	    if (HasHoloMero(index, HMERONYM))
+	    if (HasHoloMero(idx, HMERONYM))
 		retval |= bit(HMERONYM);
-	    if (HasHoloMero(index, HHOLONYM))
+	    if (HasHoloMero(idx, HHOLONYM))
 		retval |= bit(HHOLONYM);
 
@@ -1906,5 +1943,5 @@
 	}
 
-	free_index(index);
+	free_index(idx);
 	wnresults.numforms++;
     }
@@ -1915,5 +1952,6 @@
    meronyms or holonyms. */
 
-static int HasHoloMero(IndexPtr index, int ptrtyp)
+static int
+HasHoloMero(IndexPtr idx, int ptyp)
 {
     int i, j;
@@ -1922,8 +1960,8 @@
     int ptrbase;
 
-    ptrbase = (ptrtyp == HMERONYM) ? HASMEMBERPTR : ISMEMBERPTR;
+    ptrbase = (ptyp == HMERONYM) ? HASMEMBERPTR : ISMEMBERPTR;
     
-    for(i = 0; i < index->off_cnt; i++) {
-	synset = read_synset(NOUN, index->offset[i], "");
+    for(i = 0; i < idx->off_cnt; i++) {
+	synset = read_synset(NOUN, idx->offset[i], "");
 	for (j = 0; j < synset->ptrcount; j++) {
 	    if (synset->ptrtyp[j] == HYPERPTR) {
@@ -1941,10 +1979,10 @@
 }
 
-static int HasPtr(SynsetPtr synptr, int ptrtyp)
+static int HasPtr(SynsetPtr synptr, int ptyp)
 {
     int i;
     
     for(i = 0; i < synptr->ptrcount; i++) {
-        if(synptr->ptrtyp[i] == ptrtyp) {
+        if(synptr->ptrtyp[i] == ptyp) {
 	    return(1);
 	}
@@ -1956,5 +1994,6 @@
    word is not in WordNet. */
 
-unsigned int in_wn(char *word, int pos)
+unsigned int
+in_wn(const char *word, int pos)
 {
     int i;
@@ -1984,5 +2023,6 @@
 /* Strip off () enclosed comments from a word */
 
-static char *deadjify(char *word)
+static char *
+deadjify(char *word)
 {
     char *y;
@@ -2014,5 +2054,6 @@
     strtolower(wdbuf);
 		       
-    if (idx = index_lookup(wdbuf, getpos(synptr->pos))) {
+    idx = index_lookup(wdbuf, getpos(synptr->pos));
+    if (idx) {
 	for (i = 0; i < idx->off_cnt; i++)
 	    if (idx->offset[i] == synptr->hereiam) {
@@ -2025,5 +2066,7 @@
 }
 
-static void printsynset(char *head, SynsetPtr synptr, char *tail, int definition, int wdnum, int antflag, int markerflag)
+static void
+printsynset(const char *head, SynsetPtr synptr, const char *tail,
+    int definition, int wdnum, int antflag, int markerflag)
 {
     int i, wdcnt;
@@ -2038,5 +2081,5 @@
 
     if (offsetflag)		/* print synset offset */
-	sprintf(tbuf + strlen(tbuf),"{%8.8d} ", synptr->hereiam);
+	sprintf(tbuf + strlen(tbuf),"{%8.8ld} ", synptr->hereiam);
     if (fileinfoflag) {		/* print lexicographer file information */
 	sprintf(tbuf + strlen(tbuf), "<%s> ", lexfiles[synptr->fnum]);
@@ -2063,9 +2106,10 @@
 }
 
-static void printantsynset(SynsetPtr synptr, char *tail, int anttype, int definition)
+static void
+printantsynset(SynsetPtr synptr, const char *tail, int definition)
 {
     int i, wdcnt;
     char tbuf[SMLINEBUF];
-    char *str;
+    const char *str;
     int first = 1;
 
@@ -2073,5 +2117,5 @@
 
     if (offsetflag)
-	sprintf(tbuf,"{%8.8d} ", synptr->hereiam);
+	sprintf(tbuf,"{%8.8ld} ", synptr->hereiam);
     if (fileinfoflag) {
 	sprintf(tbuf + strlen(tbuf),"<%s> ", lexfiles[synptr->fnum]);
@@ -2113,6 +2157,6 @@
 static void catword(char *buf, SynsetPtr synptr, int wdnum, int adjmarker, int antflag)
 {
-    static char vs[] = " (vs. %s)";
-    static char *markers[] = {
+    static const char vs[] = " (vs. %s)";
+    static const char *markers[] = {
 	"",			/* UNKNOWN_MARKER */
 	"(predicate)",		/* PREDICATIVE */
@@ -2146,5 +2190,7 @@
 }
 
-static char *printant(int dbase, SynsetPtr synptr, int wdnum, char *template, char *tail)
+static const char *
+printant(int dbase, SynsetPtr synptr, int wdnum,
+    const char *template, const char *tail)
 {
     int i, j, wdoff;
@@ -2200,5 +2246,6 @@
 }
 
-static void printbuffer(char *string)
+static void
+printbuffer(const char *string)
 {
     if (overflag)
@@ -2210,11 +2257,13 @@
 }
 
-static void printsns(SynsetPtr synptr, int sense)
+static void
+printsns(SynsetPtr synptr, int sense_)
 {
-    printsense(synptr, sense);
+    printsense(synptr, sense_);
     printsynset("", synptr, "\n", DEFON, ALLWORDS, PRINT_ANTS, PRINT_MARKER);
 }
 
-static void printsense(SynsetPtr synptr, int sense)
+static void
+printsense(SynsetPtr synptr, int sense_)
 {
     char tbuf[256];
@@ -2224,7 +2273,7 @@
     if (fnflag)
 	sprintf(tbuf,"\nSense %d in file \"%s\"\n",
-		sense, lexfiles[synptr->fnum]);
+		sense_, lexfiles[synptr->fnum]);
     else
-	sprintf(tbuf,"\nSense %d\n", sense);
+	sprintf(tbuf,"\nSense %d\n", sense_);
 
     printbuffer(tbuf);
