diff --git src/cmd/INIT/mamake.c src/cmd/INIT/mamake.c
index 1cc85f1f..6785ff03 100644
--- src/cmd/INIT/mamake.c
+++ src/cmd/INIT/mamake.c
@@ -27,7 +27,7 @@
  * coded for portability
  */
 
-#define RELEASE_DATE "2024-06-25"
+#define RELEASE_DATE "2024-04-02"
 static char id[] = "\n@(#)$Id: mamake (ksh 93u+m) " RELEASE_DATE " $\0\n";
 
 #if _PACKAGE_ast
@@ -297,6 +297,7 @@ static struct				/* program state		*/
 	int		indent;		/* debug indent			*/
 	int		keepgoing;	/* do siblings on error		*/
 	int		never;		/* never execute		*/
+	int		probed;		/* probe already done		*/
 	int		verified;	/* don't bother with verify()	*/
 
 	Stream_t	streams[4];	/* input file stream stack	*/
@@ -1346,7 +1347,7 @@ static unsigned long run(Rule_t *r, char *s)
 		/* find commands in the current working directory first */
 		append(buf,
 			"case $PATH in\n"
-			".:* | :*)	;;\n"
+			".:*)	;;\n"
 			"*)	PATH=.:$PATH;;\n"
 			"esac\n"
 		);
@@ -1860,7 +1861,7 @@ static unsigned long make(Rule_t *r, int inloop, unsigned long modtime, Buf_t **
 					else
 						s = 0;
 					/* only bother if t is a path to a *.a we built (i.e. not -l...) */
-					if (t[0] && (t[0] != '-' || t[1] != 'l'))
+					if (t[0] != '-' || t[1] != 'l')
 					{
 						q = rule(expand(buf, t));
 						attributes(q, v);
@@ -2112,8 +2113,11 @@ static unsigned long make(Rule_t *r, int inloop, unsigned long modtime, Buf_t **
 				setval(state.vars, t, v);
 				if (strcmp(t, "MAMAKE_STRICT") == 0)
 					state.strict = *v ? atoi(v) : 1;
-				else if (strcmp(t, "CC") == 0)
-					probe();
+			}
+			if (!state.probed && strcmp(t, "CC") == 0)
+			{
+				state.probed = 1;
+				probe();
 			}
 			continue;
 
