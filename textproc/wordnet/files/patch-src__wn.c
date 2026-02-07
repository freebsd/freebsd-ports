--- src/wn.c	Fri May  6 13:29:09 2005
+++ src/wn.c	Mon Mar 16 23:04:47 2020
@@ -8,14 +8,14 @@
 #include <string.h>
 #include <stdlib.h>
 #include "wn.h"
 
-static char *Id = "$Id: wn.c,v 1.13 2005/01/31 19:19:09 wn Rel $";
+__FBSDID("$Id: wn.c,v 1.13 2005/01/31 19:19:09 wn Rel $");
 
 static struct {
-    char *option;		/* user's search request */
+    const char *option;		/* user's search request */
     int search;			/* search to pass findtheinfo() */
     int pos;			/* part-of-speech to pass findtheinfo() */
     int helpmsgidx;		/* index into help message table */
-    char *label;		/* text for search header message */
+    const char *label;		/* text for search header message */
 } *optptr, optlist[] = {
     { "-synsa", SIMPTR,	ADJ, 0, "Similarity" },
@@ -83,7 +84,7 @@
 
 struct {
-    char *template;		/* template for generic search message */
-    char *option;		/* text for help message */
-    char *helpstr;	
+    const char *template;		/* template for generic search message */
+    const char *option;		/* text for help message */
+    const char *helpstr;	
 } searchstr[] = {		/* index by search type type */
     { NULL, NULL, NULL },
@@ -122,11 +123,12 @@
 };
 
-static int getoptidx(char *), cmdopt(char *);
+static int getoptidx(const char *), cmdopt(const char *);
 static int searchwn(int, char *[]);
-static int do_search(char *, int, int, int, char *);
+static int do_search(char *, int, int, int, const char *);
 static int do_is_defined(char *);
 static void printusage(), printlicense(),
-       printsearches(char *, int, unsigned long);
-static int error_message(char *);
+       printsearches(const char *, int, unsigned long);
+static int error_message(const char *);
 
+int
 main(int argc,char *argv[])
@@ -214,9 +215,10 @@
 }
 
-static int do_search(char *searchword, int pos, int search, int whichsense,
-		     char *label)
+static int
+do_search(char *searchword, int pos, int search, int whichsense,
+    const char *label)
 {
     int totsenses = 0;
-    char *morphword, *outbuf;
+    const char *morphword, *outbuf;
 
     outbuf = findtheinfo(searchword, pos, search, whichsense);
@@ -242,5 +244,5 @@
     int i, found = 0;
     unsigned int search;
-    char *morphword;
+    const char *morphword;
 
     if (searchword[0] == '-') {
@@ -274,5 +276,6 @@
 }
 
-static void printsearches(char *word, int dbase, unsigned long search)
+static void
+printsearches(const char *word, int dbase, unsigned long search)
 {
     int j;
@@ -284,6 +286,5 @@
 	    printf(searchstr[j].template,
 		   partchars[dbase], partchars[dbase]);
-	    printf(searchstr[j].helpstr);
-	    printf("\n");
+	    puts(searchstr[j].helpstr);
 	}
 }
@@ -316,5 +319,6 @@
 }
 
-static int cmdopt(char *str)
+static int
+cmdopt(const char *str)
 {
 
@@ -332,5 +336,6 @@
 }
 
-static int getoptidx(char *searchtype)
+static int
+getoptidx(const char *searchtype)
 {
     int i;
@@ -343,5 +348,6 @@
 }
 
-static int error_message(char *msg)
+static int
+error_message(const char *msg)
 {
-    fprintf(stderr, msg);
+    fputs(msg, stderr);
