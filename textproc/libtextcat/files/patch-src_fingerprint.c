--- src/fingerprint.c.orig	Thu May 22 13:32:43 2003
+++ src/fingerprint.c	Thu Aug 23 22:47:07 2007
@@ -63,6 +63,10 @@
  * - put table/heap datastructure in a separate file.
  */
 
+#ifndef _UTF8_
+#define _UTF8_
+#endif
+
 #include "config.h"
 #include <stdio.h>
 #ifdef HAVE_STDLIB_H
@@ -80,10 +84,12 @@
 #include "wg_mempool.h"
 #include "constants.h"
 
+#include "utf8misc.h"
 
 #define TABLESIZE  (1<<TABLEPOW)
 #define TABLEMASK  ((TABLESIZE)-1)
 
+
 typedef struct {
 
 	sint2 rank;
@@ -134,29 +140,14 @@
 }
 
 
-/* checks if n-gram lex is a prefix of key and of length len */
-inline int issame( char *lex, char *key, int len )
-{
-	int i;
-	for (i=0; i<len; i++) {
-		if ( key[i] != lex[i] ) {
-			return 0;
-		}
-	}
-	if ( lex[i] != 0 ) {
-		return 0;
-	}
-	return 1;
-}
-
 
 /* increases frequency of ngram(p,len) */
-static inline int increasefreq( table_t *t, char *p, int len ) 
-{	
-	uint4 hash = simplehash( p, len ) & TABLEMASK;				
+static int increasefreq( table_t *t, char *p, int len )
+{
+	uint4 hash = simplehash( p, len ) & TABLEMASK;
 	entry_t *entry = t->table[ hash ];
-	
-	while ( entry ) {				
+
+	while ( entry ) {
 		if ( issame( entry->str, p, len ) ) {
 			/*** Found it! ***/
 			entry->cnt++;
@@ -168,7 +159,7 @@
 	}
 
 	/*** Not found, so create ***/
-	entry = wgmempool_alloc( t->pool, sizeof(entry_t) );
+        entry = (entry_t*)(wgmempool_alloc( t->pool, sizeof(entry_t) ));
 	strcpy( entry->str, p );
 	entry->cnt = 1;
 
@@ -181,12 +172,12 @@
 #if 0
 
 /* looks up ngram(p,len) */
-static entry_t *findfreq( table_t *t, char *p, int len ) 
-{	
-	uint4 hash = simplehash( p, len ) & TABLEMASK;				
+static entry_t *findfreq( table_t *t, char *p, int len )
+{
+	uint4 hash = simplehash( p, len ) & TABLEMASK;
 	entry_t *entry = t->table[ hash ];
-	
-	while ( entry ) {				
+
+	while ( entry ) {
 		if ( issame( entry->str, p, len ) ) {
 			return entry;
 		}
@@ -219,7 +210,7 @@
 #define GREATER(x,y) ((x).cnt > (y).cnt)
 #define LESS(x,y)    ((x).cnt < (y).cnt)
 
-inline static void siftup( table_t *t, unsigned int child )
+static void siftup( table_t *t, unsigned int child )
 {
 	entry_t *heap = t->heap;
 	unsigned int parent = (child-1) >> 1;
@@ -241,7 +232,7 @@
 }
 
 
-inline static void siftdown( table_t *t, unsigned int heapsize, uint4 parent )
+static void siftdown( table_t *t, unsigned int heapsize, uint4 parent )
 {
 	entry_t *heap = t->heap;
 	unsigned int child = parent*2 + 1;
@@ -458,21 +449,27 @@
 	return dest;
 }
 
-
+/**
+* this function extract all n-gram from past buffer and put them into the table "t"
+* [modified] by Jocelyn Merand to accept utf-8 multi-character symbols to be used in OpenOffice
+*/
 static void createngramtable( table_t *t, const char *buf )
 {
 	char n[MAXNGRAMSIZE+1];
 	const char *p = buf;
 	int i;
+        int pointer = 0;
 
 	/*** Get all n-grams where 1<=n<=MAXNGRAMSIZE. Allow underscores only at borders. ***/
-	for (;;p++) {
+	while(1) {
 
-		const char *q = p;
+     const char *q = &p[pointer];   /*[modified] previously p++ above (for(;;p++)) now, it's pointer wich is increased so we have to get the new pointer on the buffer*/
 		char *m = n;
 
 		/*** First char may be an underscore ***/
-		*m++ = *q++;
+                int decay = charcopy(q, m); /*[modified] previously *q++ = *m++*/
+                q = &(p[pointer+decay]);    /*[modified] the old copying method do not manage multi-character symbols*/
+                m += decay; /*[modified]*/
 		*m = '\0';
 
 		increasefreq( t, n, 1 );
@@ -482,19 +479,22 @@
 		}
 
 		/*** Let the compiler unroll this ***/
-		for ( i=2; i<=MAXNGRAMSIZE; i++) {
+		for ( i=2; i<=MAXNGRAMSYMBOL; i++) {
 
-			*m++ = *q;
+                        decay = charcopy(q, m); /*[modified] like above*/
+                        m += decay;
 			*m = '\0';
 
 			increasefreq( t, n, i );
 
 			if ( *q == '_' ) break;
-			q++;
+                        q += decay;
 			if ( *q == '\0' ) {
 				return;
 			}
 		}
+
+  pointer = nextcharstart(p,pointer);   /*[modified] p[pointer] must point on the next start of symbol, but whith utf next start is not surely next char*/
 	}
 	return;
 }
