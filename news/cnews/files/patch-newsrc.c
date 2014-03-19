--- readnews/newsrc.c.orig	1995-04-28 03:12:19.000000000 +0200
+++ readnews/newsrc.c	2014-02-07 17:01:23.000000000 +0100
@@ -30,7 +30,7 @@
 		error("No $HOME in environment.");
 	rcname = newstr3(rcname, "/", nrcname);
 	if ((f = fopen(rcname, "r")) == NULL)
-		return;
+		return 0;
 
 	rclineno = 0;
 	while (getline(f, word, rest))
@@ -39,6 +39,7 @@
 		else
 			dorcline(word, rest);
 	(void) fclose(f);
+	return 0;
 }
 
 /*
@@ -101,7 +102,7 @@
 	while (isspace(*cp))
 		cp++;
 	if (!*cp)
-		return;
+		return 0;
 
 	argc = 2;
 	argv = (char **) myalloc(2 * sizeof(char *));
@@ -120,6 +121,7 @@
 	if (options(argc, argv, false) < 0)
 		error("Bad options: %s line %d: %s", rcname, rclineno, s);
 	free((char *) argv);
+	return 0;
 }
 
 /*
@@ -210,7 +212,7 @@
 				donesome = true;
 				switch (act = (*func)(ap, np, false, false)) {
 				case stop:		
-					return;
+					return 0;
 				case next:		
 					continue;
 				case nextgroup:		
@@ -226,6 +228,7 @@
 		if (act != searchgroup && dolast && donesome)
 			act = (*func)(NIL(active), NIL(newsrc), true, false);
 	} while (act == searchgroup);
+	return 0;
 }
 
 /*
@@ -281,7 +284,7 @@
 	extern int usize;
 
 	if (!rc && (!rcgrps || !*rcgrps))
-		return;
+		return 0;
 
 	signal(SIGINT, SIG_IGN);
 	signal(SIGQUIT, SIG_IGN);
@@ -301,6 +304,7 @@
 		for (np = rc; np; np = np->n_next)
 			writengline(f, np);
 	(void) fclose(f);
+	return 0;
 }
 
 static int
