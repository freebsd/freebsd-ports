--- lib/morph.c	Fri May  6 13:17:39 2005
+++ lib/morph.c	Tue Dec 20 23:21:44 2005
@@ -19,7 +19,7 @@
 #endif
 
-static char *Id = "$Id: morph.c,v 1.67 2006/11/14 21:00:23 wn Exp $";
+__FBSDID("$Id: morph.c,v 1.67 2006/11/14 21:00:23 wn Exp $");
 
-static char *sufx[] ={ 
+static const char *sufx[] ={ 
     /* Noun suffixes */
     "s", "ses", "xes", "zes", "ches", "shes", "men", "ies",
@@ -30,5 +30,5 @@
 };
 
-static char *addr[] ={ 
+static const char *addr[] ={ 
     /* Noun endings */
     "", "s", "x", "z", "ch", "sh", "man", "y",
@@ -43,35 +43,36 @@
 static char msgbuf[256];
 
-#define NUMPREPS	15
 
 static struct {
-    char *str;
+    const char *str;
     int strlen;
-} prepositions[NUMPREPS] = {
-    "to", 2,
-    "at", 2,
-    "of", 2,
-    "on", 2,
-    "off", 3,
-    "in", 2,
-    "out", 3,
-    "up", 2,
-    "down", 4,
-    "from", 4,
-    "with", 4,
-    "into", 4,
-    "for", 3,
-    "about", 5,
-    "between", 7,
+} prepositions[] = {
+    { "to", 2 },
+    { "at", 2 },
+    { "of", 2 },
+    { "on", 2 },
+    { "off", 3 },
+    { "in", 2 },
+    { "out", 3 },
+    { "up", 2 },
+    { "down", 4 },
+    { "from", 4 },
+    { "with", 4 },
+    { "into", 4 },
+    { "for", 3 },
+    { "about", 5 },
+    { "between", 7 }
 };
 
+#define NUMPREPS	sizeof(prepositions)/sizeof(prepositions[0])
+
 static FILE *exc_fps[NUMPARTS + 1];
 
-static int do_init();
-static int strend(char *, char *);
-static char *wordbase(char *, int);
-static int hasprep(char *, int);
-static char *exc_lookup(char *, int);
-static char *morphprep(char *);
+static int do_init(void);
+static int strend(const char *, const char *);
+static const char *wordbase(const char *, int);
+static int hasprep(const char *, unsigned int);
+static const char *exc_lookup(const char *, int);
+static const char *morphprep(const char *);
 
 /* Open exception list files */
@@ -167,13 +168,15 @@
    with NULL argument return additional baseforms for original string. */
 
-char *morphstr(char *origstr, int pos)
+const char *
+morphstr(const char *origstr, int pos)
 {
     static char searchstr[WORDBUF], str[WORDBUF];
     static int svcnt, svprep;
-    char word[WORDBUF], *tmp;
+    char word[WORDBUF];
+    const char *tmp;
     int cnt, st_idx = 0, end_idx;
     int prep;
-    char *end_idx1, *end_idx2;
-    char *append;
+    const char *end_idx1, *end_idx2;
+    const char *append;
     
     if (pos == SATELLITE)
@@ -230,5 +233,6 @@
 		strncpy(word, str + st_idx, end_idx - st_idx);
 		word[end_idx - st_idx] = '\0';
-		if(tmp = morphword(word, pos))
+		tmp = morphword(word, pos);
+		if(tmp)
 		    strcat(searchstr,tmp);
 		else
@@ -238,5 +242,6 @@
 	    }
 	    
-	    if(tmp = morphword(strcpy(word, str + st_idx), pos)) 
+	    tmp = morphword(strcpy(word, str + st_idx), pos);
+	    if(tmp)
 		strcat(searchstr,tmp);
 	    else
@@ -264,13 +269,14 @@
 
 /* Try to find baseform (lemma) of individual word in POS */
-char *morphword(char *word, int pos)
+const char *
+morphword(const char *word, int pos)
 {
     int offset, cnt;
     int i;
     static char retval[WORDBUF];
-    char *tmp, tmpbuf[WORDBUF], *end;
+    char tmpbuf[WORDBUF];
+    const char *tmp, *end;
     
-    sprintf(retval,"");
-    sprintf(tmpbuf, "");
+    retval[0] = tmpbuf[0] = '\0';
     end = "";
     
@@ -315,7 +321,7 @@
 }
 
-static int strend(char *str1, char *str2)
+static int strend(const char *str1, const char *str2)
 {
-    char *pt1;
+    const char *pt1;
     
     if(strlen(str2) >= strlen(str1))
@@ -329,5 +335,6 @@
 }
 
-static char *wordbase(char *word, int ender)
+static const char *
+wordbase(const char *word, int ender)
 {
     char *pt1;
@@ -344,10 +351,10 @@
 }
 
-static int hasprep(char *s, int wdcnt)
+static int hasprep(const char *s, unsigned int wdcnt)
 {
     /* Find a preposition in the verb string and return its
        corresponding word number. */
 
-    int i, wdnum;
+    unsigned int i, wdnum;
 
     for (wdnum = 2; wdnum <= wdcnt; wdnum++) {
@@ -362,9 +369,9 @@
 }
  
-static char *exc_lookup(char *word, int pos)
+static const char *
+exc_lookup(const char *word, int pos)
 {
     static char line[WORDBUF], *beglp, *endlp;
-    char *excline;
-    int found = 0;
+    const char *excline;
 
     if (exc_fps[pos] == NULL)
@@ -394,7 +401,8 @@
 }
 
-static char *morphprep(char *s)
+static const char *
+morphprep(const char *s)
 {
-    char *rest, *exc_word, *lastwd = NULL, *last;
+    const char *rest, *exc_word, *lastwd = NULL, *last;
     int i, offset, cnt;
     char word[WORDBUF], end[WORDBUF];
@@ -408,5 +416,6 @@
     last = strrchr(s, '_');
     if (rest != last) {		/* more than 2 words */
-	if (lastwd = morphword(last + 1, NOUN)) {
+	lastwd = morphword(last + 1, NOUN);
+	if (lastwd) {
 	    strncpy(end, rest, last - rest + 1);
 	    end[last-rest+1] = '\0';
