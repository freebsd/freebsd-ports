--- src/cmd/ksh93/sh/macro.c.orig	2023-06-08 23:30:08.000000000 -0700
+++ src/cmd/ksh93/sh/macro.c	2023-06-12 19:26:31.718942000 -0700
@@ -76,6 +76,7 @@
 	char		macsub;		/* set to 1 when running mac_substitute */
 	int		dotdot;		/* set for .. in subscript */
 	void		*nvwalk;	/* for name space walking */
+	char		bracketexpr; 	/* set when in [brackets] within a non-ERE glob pattern */
 } Mac_t;
 
 #undef ESCAPE
@@ -437,7 +438,6 @@
 	char		oldquote = mp->quote;	/* save "double quoted" state */
 	char		ansi_c = 0;		/* set when processing ANSI C escape codes */
 	int32_t		ere = 0;		/* bitmask of pattern options indicating an extended regular expression */
-	char		bracketexpr = 0; 	/* set when in [brackets] within a non-ERE glob pattern */
 	Sfio_t		*sp = mp->sp;
 	Stk_t		*stkp = sh.stk;
 	char		*resume = 0;
@@ -533,7 +533,7 @@
 			if(mp->pattern)
 			{
 				/* preserve \ for escaping glob pattern bracket expression operators */
-				if(bracketexpr && n==S_BRAOP)
+				if(mp->bracketexpr && n==S_BRAOP)
 					break;
 				/* preserve \digit for pattern matching */
 				/* also \alpha for extended patterns */
@@ -636,8 +636,8 @@
 				mp->pattern = c;
 			break;
 		    case S_ENDCH:
-			if(bracketexpr && cp[-1]==RBRACT && !(mp->quote || mp->lit))
-				bracketexpr--;
+			if(mp->bracketexpr && cp[-1]==RBRACT && !(mp->quote || mp->lit))
+				mp->bracketexpr--;
 			if((mp->lit || cp[-1]!=endch || mp->quote!=newquote))
 				goto pattern;
 			if(endch==RBRACE && mp->pattern && brace)
@@ -738,12 +738,12 @@
 				cp = first = fcseek(0);
 				break;
 			}
-			if(mp->pattern==1 && !ere && !bracketexpr)
+			if(mp->pattern==1 && !ere && !mp->bracketexpr)
 			{
-				bracketexpr++;
+				mp->bracketexpr++;
 				/* a ] following [, as in []abc], should not close the bracket expression */
 				if(cp[0]==RBRACT && cp[1])
-					bracketexpr++;
+					mp->bracketexpr++;
 			}
 			/* FALLTHROUGH */
 		    case S_PAT:
@@ -883,7 +883,7 @@
 			break;
 		    case S_BRAOP:
 			/* escape a quoted !^- within a bracket expression */
-			if(!bracketexpr || !(mp->quote || mp->lit))
+			if(!mp->bracketexpr || !(mp->quote || mp->lit))
 				continue;
 			if(c)
 				sfwrite(stkp,first,c);
@@ -2481,7 +2481,10 @@
 				continue;
 			}
 			if(n==S_ESC)
-				sfputc(stkp,ESCAPE);
+			{
+				if(!mp->bracketexpr)
+					sfputc(stkp,ESCAPE);
+			}
 			else if(n==S_EPAT)
 			{
 				/* don't allow extended patterns in this case */
@@ -2583,7 +2586,7 @@
 		mp->atmode = 0;
 		if(mp->patfound)
 		{
-			int musttrim = mp->wasexpan && !mp->noextpat && strchr(argp->argval,'\\');
+			int musttrim = mp->wasexpan && !mp->quoted && !mp->noextpat && strchr(argp->argval,'\\');
 			sh.argaddr = 0;
 #if SHOPT_BRACEPAT
 			/* in POSIX mode, disallow brace expansion for unquoted expansions */
