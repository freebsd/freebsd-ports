diff -u ../old/FD-1.03u/parse.c ./parse.c
--- ../old/FD-1.03u/parse.c	Tue Dec 18 00:00:00 2001
+++ ./parse.c	Mon Jan 21 10:15:02 2002
@@ -322,11 +322,16 @@
 	epath = next = NULL;
 	size = 0;
 	for (cp = path; cp && *cp; cp = next) {
-		next = strtkbrk(cp, delim, 0);
-		len = (next) ? (next++) - cp : strlen(cp);
-		if (!len) next = cp;
+		if ((next = strtkbrk(cp, delim, 0))) {
+			len = next - cp;
+			for (i = 1; next[i] && strchr(delim, next[i]); i++);
+		}
 		else {
-			next = cp + len;
+			len = strlen(cp);
+			i = 0;
+		}
+		next = cp + len;
+		if (len) {
 			tmp = _evalpath(cp, next, 0, 0);
 # if	!MSDOS && !defined (_NOKANJIFCONV)
 			cp = kanjiconv2(buf, tmp,
@@ -336,17 +341,18 @@
 # endif
 			len = strlen(cp);
 		}
-		for (i = 1; next[i] && strchr(delim, next[i]); i++);
 
 		epath = (char *)realloc2(epath, size + len + i + 1);
 		if (len) {
 			strcpy(epath + size, cp);
 			free(tmp);
+			size += len;
+		}
+		if (i) {
+			strncpy(epath + size, next, i);
+			size += i;
+			next += i;
 		}
-		size += len;
-		strncpy(epath + size, next, i);
-		size += i;
-		next += i;
 	}
 
 	if (!epath) return(strdup2(""));
