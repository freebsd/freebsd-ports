--- explode/trbatch.c.orig	1994-11-30 23:09:10.000000000 +0100
+++ explode/trbatch.c	2014-02-07 18:02:12.000000000 +0100
@@ -23,6 +23,9 @@
 
 static HASHTABLE *nmbftbl;		/* name -> batchfile mapping */
 
+static struct batchfile *bfisopen(char *name), *bfincache(char *name);
+static statust bfrealclose(), bfrclose();
+
 /*
  * open "name" for appending.
  *
@@ -69,7 +72,7 @@
 		nmbftbl = hashcreate(HASHFILSZ, (unsigned (*)())NULL);
 	bf = (struct batchfile *)hashfetch(nmbftbl, name);
 	if (bf != NULL)
-		return;			/* error: name present */
+		return 0;			/* error: name present */
 	/* allocate, append & initialise a new entry */
 	bf = (struct batchfile *)nemalloc(sizeof *bf);
 	(void) memset((char *)bf, 0, sizeof *bf);
@@ -81,12 +84,13 @@
 	bf->bf_lines = FLUSHEVERY;
 	if (!hashstore(nmbftbl, bf->bf_name, (HASHDATUM)bf))
 		error("can't store under hash key `%s'", name);	/* canthappen */
+	return 0;
 }
 
 /*
  * returns a batchfile, never NULL, corresponding to name.
  */
-struct batchfile *
+static struct batchfile *
 bfincache(name)
 char *name;
 {
@@ -152,12 +156,13 @@
 	register struct batchfile *bf;
 
 	if (chp->closedone)
-		return;
+		return 0;
 	bf = (struct batchfile *)data;
 	if (bf->bf_str == NULL)
-		return;
+		return 0;
 	chp->status = bfclose(bf);
 	chp->closedone = YES;
+	return 0;
 }
 
 STATIC statust
@@ -194,6 +199,7 @@
 #endif
 	if (!hashdelete(nmbftbl, key))
 		error("can't delete hash key `%s'", key);	/* canthappen */
+	return 0;
 }
 
 STATIC statust
--- relay/trbatch.c.orig	1993-01-15 05:27:11.000000000 +0100
+++ relay/trbatch.c	2014-02-07 18:02:37.000000000 +0100
@@ -14,6 +14,8 @@
 #include "msgs.h"
 #include "trbatch.h"
 
+static struct batchfile *bfincache(char *name, int ord);
+
 /* tunable parameters */
 #ifndef MASTERDIR
 #define MASTERDIR artfile("out.master")
@@ -89,7 +91,7 @@
 		nmordtbl = hashcreate(HASHFILSZ, (unsigned (*)())NULL);
 	hf = (struct hashfilename *)hashfetch(nmordtbl, name);
 	if (hf != NULL)
-		return;			/* error: name present */
+		return 0;			/* error: name present */
 	/* allocate, append & initialise a new entry */
 	hf = (struct hashfilename *)nemalloc(sizeof *hf);
 	hf->hf_mbf = mbford;
@@ -97,6 +99,7 @@
 		errunlock("can't store under hash key `%s'", name);
 	ordtombfs[ord] = mbford;
 	otomvalid[ord] = YES;
+	return 0;
 }
 
 
