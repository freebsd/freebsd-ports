--- misc.c	Mon Dec 23 02:44:36 2002
+++ misc.c	Wed Sep 17 00:50:27 2003
@@ -308,18 +308,21 @@ addargs(arglist *args, char *fmt, ...)
 {
 	va_list ap;
 	char buf[1024];
+	int nalloc;
 
 	va_start(ap, fmt);
 	vsnprintf(buf, sizeof(buf), fmt, ap);
 	va_end(ap);
 
+	nalloc = args->nalloc;
 	if (args->list == NULL) {
-		args->nalloc = 32;
+		nalloc = 32;
 		args->num = 0;
-	} else if (args->num+2 >= args->nalloc)
-		args->nalloc *= 2;
+	} else if (args->num+2 >= nalloc)
+		nalloc *= 2;
 
-	args->list = xrealloc(args->list, args->nalloc * sizeof(char *));
+	args->list = xrealloc(args->list, nalloc * sizeof(char *));
+	args->nalloc = nalloc;
 	args->list[args->num++] = xstrdup(buf);
 	args->list[args->num] = NULL;
 }
