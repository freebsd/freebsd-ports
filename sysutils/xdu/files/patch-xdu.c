--- xdu.c.orig	2014-10-14 03:21:53.000000000 -0700
+++ xdu.c	2025-04-28 11:49:41.485062000 -0700
@@ -20,9 +20,12 @@
  * the party supplying this software to the X Consortium.
  */
 #include <stdio.h>
+#include <string.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <ctype.h>
 #include "version.h"
 
-extern char *malloc(), *calloc();
 
 #define	MAXDEPTH	80	/* max elements in a path */
 #define	MAXNAME		1024	/* max pathname element length */
@@ -234,6 +237,7 @@
 	char	buf[4096];
 	int	size;
 	FILE	*fp;
+	char	*p, *n;
 
 	if (strcmp(filename, "-") == 0) {
 		fp = stdin;
@@ -271,7 +275,7 @@
 	name[length] = 0;
 	if ((length > 0) && (name[length-1] == '/')) {
 		/* strip off trailing / (e.g. GNU du) */
-		name[length-1] = 0;
+		name[--length] = 0;
 	}
 
 	arg = 0; indx = 0;
@@ -291,8 +295,10 @@
 		}
 		name++;
 	}
-	buf[indx] = 0;
-	path[arg++] = strdup(buf);
+	if (length) {
+		buf[indx] = 0;
+		path[arg++] = strdup(buf);
+	}
 	path[arg] = NULL;
 
 	addtree(&top,path,size);
@@ -400,16 +406,16 @@
 	struct	node *np;
 
 	/*printf("addtree(\"%s\",\"%s\",%d)\n", top->name, path[0], size);*/
+
+	if (path[0] == NULL) {
+		/* end of the chain, save size */
+		top->size = size;
+		return;
+	}
 
 	/* check all children for a match */
 	for (np = top->child; np != NULL; np = np->peer) {
 		if (strcmp(path[0],np->name) == 0) {
-			/* name matches */
-			if (path[1] == NULL) {
-				/* end of the chain, save size */
-				np->size = size;
-				return;
-			}
 			/* recurse */
 			addtree(np,&path[1],size);
 			return;
@@ -623,7 +629,7 @@
 	printf("%s %d (%.2f%%)\n", path, topp->size,
 		100.0*topp->size/rootp->size);
 }
-
+/*
 char *
 strdup(s)
 char *s;
@@ -637,7 +643,7 @@
 
 	return	cp;
 }
-
+*/
 /**************** External Entry Points ****************/
 
 int
