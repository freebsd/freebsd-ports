--- include/wn.h	Wed Jul  6 14:48:44 2005
+++ include/wn.h	Wed Dec 21 17:24:58 2005
@@ -152,12 +154,12 @@
 #define IMMED_POSTNOMINAL	IPADJ
 
-extern char *wnrelease;		/* WordNet release/version number */
+extern const char *wnrelease;		/* WordNet release/version number */
 
-extern char *lexfiles[];	/* names of lexicographer files */
-extern char *ptrtyp[];		/* pointer characters */
-extern char *partnames[];	/* POS strings */
-extern char partchars[];	/* single chars for each POS */
-extern char *adjclass[];	/* adjective class strings */
-extern char *frametext[];	/* text of verb frames */
+extern const char *lexfiles[];	/* names of lexicographer files */
+extern const char *ptrtyp[];		/* pointer characters */
+extern const char *partnames[];	/* POS strings */
+extern const char partchars[];	/* single chars for each POS */
+extern const char *adjclass[];	/* adjective class strings */
+extern const char *frametext[];	/* text of verb frames */
 
 /* Data structures used by search code functions. */
@@ -173,5 +175,5 @@
     unsigned long *offset;	/* offsets of synsets containing word */
     int ptruse_cnt;		/* number of pointers used */
-    int *ptruse;		/* pointers used */
+    short *ptruse;		/* pointers used */
 } Index;
 
@@ -180,5 +182,5 @@
 /* Structure for data file synset */
 typedef struct ss {
-    long hereiam;		/* current file position */
+    unsigned long hereiam;	/* current file position */
     int sstype;			/* type of ADJ synset */
     int fnum;			/* file number that synset comes from */
@@ -191,8 +193,8 @@
     int ptrcount;		/* number of pointers */
     int *ptrtyp;		/* pointer types */
-    long *ptroff;		/* pointer offsets */
+    unsigned long *ptroff;	/* pointer offsets */
     int *ppos;			/* pointer part of speech */
-    int *pto;			/* pointer 'to' fields */
-    int *pfrm;			/* pointer 'from' fields */
+    unsigned short *pto;	/* pointer 'to' fields */
+    unsigned short *pfrm;	/* pointer 'from' fields */
     int fcount;			/* number of verb frames */
     int *frmid;			/* frame numbers */
@@ -218,5 +220,5 @@
     char *sensekey;		/* sense key */
     char *word;			/* word string */
-    long loc;			/* synset offset */
+    unsigned long loc;		/* synset offset */
     int wnsense;		/* WordNet sense number */
     int tag_cnt;		/* number of semantic tags to sense */
@@ -268,6 +270,6 @@
    Default function provided in library returns -1 */
 
-extern int default_display_message(char *);
-extern int (*display_message)(char *);
+int default_display_message(const char *);
+int (*display_message)(const char *);
 
 
@@ -282,5 +284,5 @@
 
 /* Primry search algorithm for use with user interfaces */
-extern char *findtheinfo(char *, int, int, int);	
+const char *findtheinfo(const char *, int, int, int);	
 
 /* Primary search algorithm for use with programs (returns data structure) */
@@ -289,27 +291,27 @@
 /* Set bit for each search type that is valid for the search word
    passed and return bit mask. */
-extern unsigned int is_defined(char *, int); 
+extern unsigned int is_defined(const char *, int); 
 
 /* Set bit for each POS that search word is in.  0 returned if
    word is not in WordNet. */
-extern unsigned int in_wn(char *, int);	
+unsigned int in_wn(const char *, int);	
 
 /* Find word in index file and return parsed entry in data structure.
    Input word must be exact match of string in database. */
-extern IndexPtr index_lookup(char *, int); 
+IndexPtr index_lookup(const char *, int); 
 
 /* 'smart' search of index file.  Find word in index file, trying different
    techniques - replace hyphens with underscores, replace underscores with
    hyphens, strip hyphens and underscores, strip periods. */
-extern IndexPtr getindex(char *, int);	
-extern IndexPtr parse_index(long, int, char *);
+extern IndexPtr getindex(const char *, int);	
+extern IndexPtr parse_index(long, int, const char *);
 
 /* Read synset from data file at byte offset passed and return parsed
    entry in data structure. */
-extern SynsetPtr read_synset(int, long, char *);
+extern SynsetPtr read_synset(int, long, const char *);
 
 /* Read synset at current byte offset in file and return parsed entry
    in data structure. */
-extern SynsetPtr parse_synset(FILE *, int, char *); 
+extern SynsetPtr parse_synset(FILE *, int, const char *); 
 
 /* Free a synset linked list allocated by findtheinfo_ds() */
@@ -324,22 +326,22 @@
 /* Recursive search algorithm to trace a pointer tree and return results
    in linked list of data structures. */
-SynsetPtr traceptrs_ds(SynsetPtr, int, int, int);
+SynsetPtr traceptrs_ds(SynsetPtr, int, int);
 
 /* Do requested search on synset passed, returning output in buffer. */
-extern char *do_trace(SynsetPtr, int, int, int);
+const char *do_trace(SynsetPtr, int, int, int);
 
 /*** Morphology functions (morph.c) ***/
 
 /* Open exception list files */
-extern int morphinit();	
+int morphinit(void);	
 
 /* Close exception list files and reopen */
-extern int re_morphinit();	
+int re_morphinit(void);	
 
 /* Try to find baseform (lemma) of word or collocation in POS. */
-extern char *morphstr(char *, int);	
+const char *morphstr(const char *, int);	
 
 /* Try to find baseform (lemma) of individual word in POS. */
-extern char *morphword(char *, int);	
+const char *morphword(const char *, int);	
 
 /*** Utility functions (wnutil.c) ***/
@@ -347,9 +349,9 @@
 /* Top level function to open database files, initialize wn_filenames,
    and open exeception lists. */
-extern int wninit();		
+int wninit(void);		
 
 /* Top level function to close and reopen database files, initialize
    wn_filenames and open exception lists. */
-extern int re_wninit();	
+int re_wninit(void);
 
 /* Count the number of underscore or space separated words in a string. */
@@ -358,4 +360,5 @@
 /* Convert string to lower case remove trailing adjective marker if found */
 extern char *strtolower(char *);	
+char *strtolower2(const char *from, char *to);	
 
 /* Convert string passed to lower case */
@@ -366,14 +369,14 @@
 
 /* Return pointer code for pointer type characer passed. */
-extern int getptrtype(char *);	
+unsigned short getptrtype(const char *, char **end);	
 
 /* Return part of speech code for string passed */
-extern int getpos(char *);		
+int getpos(const char *);		
 
 /* Return synset type code for string passed. */
-extern int getsstype(char *);		
+int getsstype(const char *);		
 
 /* Reconstruct synset from synset pointer and return ptr to buffer */
-extern char *FmtSynset(SynsetPtr, int);	
+const char *FmtSynset(SynsetPtr, int);	
 
 /* Find string for 'searchstr' as it is in index file */
@@ -381,37 +384,34 @@
 
 /* Pass in string for POS, return corresponding integer value */
-extern int StrToPos(char *);
+int StrToPos(const char *);
 
 /* Return synset for sense key passed. */
-extern SynsetPtr GetSynsetForSense(char *);
+SynsetPtr GetSynsetForSense(const char *);
 
 /* Find offset of sense key in data file */
-extern long GetDataOffset(char *);
+long GetDataOffset(const char *);
 
 /* Find polysemy (collins) count for sense key passed. */
-extern int GetPolyCount(char *);
+int GetPolyCount(const char *);
 
 /* Return word part of sense key */
-extern char *GetWORD(char *);
+const char *GetWORD(const char *);
 
 /* Return POS code for sense key passed. */
-extern int GetPOS(char *);
+int GetPOS(const char *);
 
 /* Convert WordNet sense number passed of IndexPtr entry to sense key. */
 extern char *WNSnsToStr(IndexPtr, int);
 
-/* Search for string and/or baseform of word in database and return
-   index structure for word if found in database. */
-extern IndexPtr GetValidIndexPointer(char *, int);
-
 /* Return sense number in database for word and lexsn passed. */
-int GetWNSense(char *, char *);
+int GetWNSense(const char *, const char *);
 
-SnsIndexPtr GetSenseIndex(char *);
+SnsIndexPtr GetSenseIndex(const char *);
+void FreeSenseIndex(SnsIndexPtr);
 
-char *GetOffsetForKey(unsigned int);
-unsigned int GetKeyForOffset(char *);
+const char *GetOffsetForKey(unsigned int);
+unsigned int GetKeyForOffset(const char *);
 
-char *SetSearchdir();
+const char *SetSearchdir(void);
 
 /* Return number of times sense is tagged */
@@ -435,17 +435,6 @@
 /* General purpose binary search function to search for key as first
    item on line in open file.  Item is delimited by space. */
-extern char *bin_search(char *, FILE *);
-extern char *read_index(long, FILE *);
-
-/* Copy contents from one file to another. */
-extern void copyfile(FILE *, FILE *);
-
-/* Function to replace a line in a file.  Returns the original line,
-   or NULL in case of error. */
-extern char *replace_line(char *, char *, FILE *);
-
-/* Find location to insert line at in file.  If line with this
-   key is already in file, return NULL. */
-extern char *insert_line(char *, char *, FILE *);
+const char *bin_search(const char *, FILE *);
+const char *read_index(long, FILE *);
 
 #ifdef __cplusplus
@@ -453,7 +453,8 @@
 #endif
 
-extern char **helptext[NUMPARTS + 1];
+const char * const * helptext[NUMPARTS + 1];
 
-static char *license = "\
+#ifdef DEFINE_LICENSE /* should live in wn.c */
+const char license[] = "\
 This software and database is being provided to you, the LICENSEE, by  \n\
 Princeton University under the following license.  By obtaining, using  \n\
@@ -486,5 +487,5 @@
 Princeton University and LICENSEE agrees to preserve same.  \n"
 ;
-
+#if 0 /* { */
 static char dblicense[] = "\
   1 This software and database is being provided to you, the LICENSEE, by  \n\
@@ -518,6 +519,9 @@
   29 Princeton University and LICENSEE agrees to preserve same.  \n"
 ;
-
 #define DBLICENSE_SIZE 	(sizeof(dblicense))
+#endif /* } */
+#else /* } { */
+extern const char license[];
+#endif /* } */
 
 #endif /*_WN_*/
