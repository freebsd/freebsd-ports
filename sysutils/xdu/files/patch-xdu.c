--- xdu.c.orig	Sun Jun  5 21:29:23 1994
+++ xdu.c	Sun Aug 15 19:31:01 2004
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
@@ -235,6 +238,7 @@
 	char	name[4096];
 	int	size;
 	FILE	*fp;
+	char	*p, *n;
 
 	if (strcmp(filename, "-") == 0) {
 		fp = stdin;
@@ -244,11 +248,21 @@
 			exit(1);
 		}
 	}
+
 	while (fgets(buf,sizeof(buf),fp) != NULL) {
-		sscanf(buf, "%d %s\n", &size, name);
+		p = buf;
+		while (*p && isspace(*p)) p++;
+		size = atoi(p);
+		while (*p && !isspace(*p)) p++;
+		while (*p && isspace(*p)) p++;
+		n = name;
+		while (*p && *p != '\n' && *p != '\r')
+			*n++ = *p++;
+		*n++ = '\0';
 		/*printf("%d %s\n", size, name);*/
 		parse_entry(name,size);
 	}
+
 	fclose(fp);
 }
 
@@ -269,7 +283,7 @@
 	length = strlen(name);
 	if ((length > 0) && (name[length-1] == '/')) {
 		/* strip off trailing / (e.g. GNU du) */
-		name[length-1] = 0;
+		name[--length] = 0;
 	}
 
 	arg = 0; indx = 0;
@@ -289,8 +303,10 @@
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
@@ -399,15 +415,15 @@
 
 	/*printf("addtree(\"%s\",\"%s\",%d)\n", top->name, path[0], size);*/
 
+	if (path[0] == NULL) {
+		/* end of the chain, save size */
+		top->size = size;
+		return;
+	}
+
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
@@ -621,7 +637,7 @@
 	printf("%s %d (%.2f%%)\n", path, topp->size,
 		100.0*topp->size/rootp->size);
 }
-
+/*
 char *
 strdup(s)
 char *s;
@@ -635,7 +651,7 @@
 
 	return	cp;
 }
-
+*/
 /**************** External Entry Points ****************/
 
 int
