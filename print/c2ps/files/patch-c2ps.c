--- c2ps.c.orig	1997-05-19 21:43:04.000000000 +0900
+++ c2ps.c	2013-04-27 18:55:52.000000000 +0900
@@ -45,7 +45,6 @@
 
 
 
-#line 2 "c2ps.c"
 #define FLEX_SCANNER
 #define YY_FLEX_MAJOR_VERSION 2
 #define YY_FLEX_MINOR_VERSION 5
@@ -1641,9 +1640,7 @@
 #define yymore() (yy_more_flag = 1)
 #define YY_MORE_ADJ yy_more_len
 char *yytext;
-#line 1 "l1.m"
 #define INITIAL 0
-#line 2 "l1.m"
 #define VERSION "4.0"
 
 #ifndef DEFAULT
@@ -1673,11 +1670,6 @@
 #ifndef DIM
 #define DIM 0.75
 #endif
-#ifdef LETTER
-#define LETTER 1
-#else
-#define LETTER 0
-#endif
 
 #define ISO "\n"\
 "%%%%BeginProlog								\n"\
@@ -1829,6 +1821,14 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#include <math.h>
+#include <paper.h>
+
+struct {
+	char *name;
+	int width, height;
+} pspec;
+
 FILE* out;			/* output stream */
 
 struct fun {			/* strucure to hold info about fun id definition */
@@ -1845,7 +1845,6 @@
 unsigned line_cut = 0;		/* global: cut long lines */
 unsigned ppl = 1;		/* global: columns per page */
 unsigned lpp = 0;		/* global: lines per page */
-unsigned letter = LETTER;	/* global: use letter paper type */
 unsigned frame = 0;		/* global: draw frame around each column */
 unsigned iso = 1;		/* global: support ISO Latin 1 encoding */
 unsigned last_modified = 1;	/* global: print the time when file was last modified */
@@ -1929,7 +1928,6 @@
 
 #define dont_highlight 4
 
-#line 1892 "c2ps.c"
 
 /* Macros after this point can all be overridden by user definitions in
  * section 1.
@@ -2079,9 +2077,7 @@
 	register char *yy_cp, *yy_bp;
 	register int yy_act;
 
-#line 301 "l1.m"
 
-#line 2044 "c2ps.c"
 
 	if ( yy_init )
 		{
@@ -2197,21 +2193,18 @@
 	{ /* beginning of action switch */
 case 1:
 YY_RULE_SETUP
-#line 302 "l1.m"
 {
                         PString(yytext);
                 }
 	YY_BREAK
 case 2:
 YY_RULE_SETUP
-#line 305 "l1.m"
 {
                         NextLine();
                 }
 	YY_BREAK
 case 3:
 YY_RULE_SETUP
-#line 308 "l1.m"
 { /*'*/
 			PFlush();
                         fprintf(out, "cf fst\n");
@@ -2221,7 +2214,6 @@
 	YY_BREAK
 case 4:
 YY_RULE_SETUP
-#line 314 "l1.m"
 {
                         PFlush();
 			while (1)
@@ -2244,7 +2236,6 @@
 	YY_BREAK
 case 5:
 YY_RULE_SETUP
-#line 333 "l1.m"
 {
 			c = yytext;
 			if (adjust_comments)
@@ -2267,12 +2258,10 @@
 	YY_BREAK
 case 6:
 YY_RULE_SETUP
-#line 352 "l1.m"
 {	yymore();		}
 	YY_BREAK
 case 7:
 YY_RULE_SETUP
-#line 353 "l1.m"
 {
 			c = yytext;
                         if (adjust_comments && comment_many_lines++)
@@ -2290,12 +2279,10 @@
 yy_c_buf_p = yy_cp = yy_bp + 1;
 YY_DO_BEFORE_ACTION; /* set up yytext again */
 YY_RULE_SETUP
-#line 364 "l1.m"
 {	yymore();		}
 	YY_BREAK
 case 9:
 YY_RULE_SETUP
-#line 366 "l1.m"
 {
 			PFlush();
 			while (1)
@@ -2316,7 +2303,6 @@
 	YY_BREAK
 case 10:
 YY_RULE_SETUP
-#line 383 "l1.m"
 {
                         PFlush();
 			while (1)
@@ -2411,7 +2397,6 @@
 	YY_BREAK
 case 11:
 YY_RULE_SETUP
-#line 474 "l1.m"
 {
                         PFill("\\");
 			PFlush();
@@ -2423,7 +2408,6 @@
 yy_c_buf_p = yy_cp -= 1;
 YY_DO_BEFORE_ACTION; /* set up yytext again */
 YY_RULE_SETUP
-#line 479 "l1.m"
 {
 			PFlush();
                         BEGIN((nesting <= 0) ? nnested : INITIAL);
@@ -2431,7 +2415,6 @@
 	YY_BREAK
 case 13:
 YY_RULE_SETUP
-#line 483 "l1.m"
 {
 			if (pd > 0 &&
 			    prep_touch[pd - 1] &&
@@ -2489,7 +2472,6 @@
 yy_c_buf_p = yy_cp -= 1;
 YY_DO_BEFORE_ACTION; /* set up yytext again */
 YY_RULE_SETUP
-#line 534 "l1.m"
 {
 			PFill(yytext);
 			PFlush();
@@ -2503,7 +2485,6 @@
 yy_c_buf_p = yy_cp -= 1;
 YY_DO_BEFORE_ACTION; /* set up yytext again */
 YY_RULE_SETUP
-#line 541 "l1.m"
 {
 			PFlush();
                         fprintf(out, "cf fty\n");
@@ -2516,7 +2497,6 @@
 yy_c_buf_p = yy_cp -= 1;
 YY_DO_BEFORE_ACTION; /* set up yytext again */
 YY_RULE_SETUP
-#line 547 "l1.m"
 {
 			PFill(yytext);
 			PFlush();
@@ -2530,7 +2510,6 @@
 yy_c_buf_p = yy_cp -= 1;
 YY_DO_BEFORE_ACTION; /* set up yytext again */
 YY_RULE_SETUP
-#line 554 "l1.m"
 {
 			PFlush();
                         fprintf(out, "cf %s\n", (ext) ? "fty" : "fdf");
@@ -2543,7 +2522,6 @@
 yy_c_buf_p = yy_cp -= 1;
 YY_DO_BEFORE_ACTION; /* set up yytext again */
 YY_RULE_SETUP
-#line 560 "l1.m"
 {
 			PFill(yytext);
 			PFlush();
@@ -2557,7 +2535,6 @@
 yy_c_buf_p = yy_cp -= 1;
 YY_DO_BEFORE_ACTION; /* set up yytext again */
 YY_RULE_SETUP
-#line 567 "l1.m"
 {
 			PFlush();
                         fprintf(out, "cf fke\n");
@@ -2570,7 +2547,6 @@
 yy_c_buf_p = yy_cp -= 1;
 YY_DO_BEFORE_ACTION; /* set up yytext again */
 YY_RULE_SETUP
-#line 573 "l1.m"
 {
 			PFill(yytext);
 			PFlush();
@@ -2584,7 +2560,6 @@
 yy_c_buf_p = yy_cp -= 1;
 YY_DO_BEFORE_ACTION; /* set up yytext again */
 YY_RULE_SETUP
-#line 580 "l1.m"
 {
 			PFlush();
                         fprintf(out, "cf %s\n", (ext) ? "fke" : "fdf");
@@ -2594,7 +2569,6 @@
 	YY_BREAK
 case 22:
 YY_RULE_SETUP
-#line 586 "l1.m"
 {
 			PFlush();
 			if (! (pd > 0 &&
@@ -2604,17 +2578,14 @@
 	YY_BREAK
 case 23:
 YY_RULE_SETUP
-#line 592 "l1.m"
 {
                         PFill(yytext);
 		}
 	YY_BREAK
 case 24:
 YY_RULE_SETUP
-#line 595 "l1.m"
 ECHO;
 	YY_BREAK
-#line 2577 "c2ps.c"
 			case YY_STATE_EOF(INITIAL):
 			case YY_STATE_EOF(comm):
 			case YY_STATE_EOF(preps):
@@ -3479,7 +3450,6 @@
 	return 0;
 	}
 #endif
-#line 595 "l1.m"
 
 
 #ifdef YY_USE_PROTOS
@@ -3680,7 +3650,7 @@
 	      page / ppl + 1, total_page / ppl +1);
       if (page > 0 && comment)
 	fprintf(out, "setgray\n");
-      if (letter)
+      if (strncasecmp(pspec.name, "letter", 7) == 0)
 	fprintf(out, "0.93 0.93 scale 31 8 translate\n");
       switch(ppl)
 	{
@@ -3917,6 +3887,34 @@
   return 1;
 }
 
+void getpaper(char *name)
+{
+	const struct paper *pp;
+
+	if (name == NULL) {
+		name = (char *)systempapername();
+		if (name == NULL)
+			name = (char *)defaultpapername();
+	}
+
+	/* Support only A4 or letter. */
+	if (strncasecmp(name, "a4", 3) != 0 &&
+	    strncasecmp(name, "letter", 7) != 0) {
+		fprintf(stderr, "Unsupported paper size: %s.  "
+		    "A4 size will be used instead.\n", name);
+		name = "a4";
+	}
+
+	paperinit();
+	for (pp = paperfirst(); pp; pp = papernext(pp)) {
+		if (strcmp(name, papername(pp)) == 0) {
+			pspec.name = strdup(name);
+			pspec.width = round(paperpswidth(pp));
+			pspec.height = round(paperpsheight(pp));
+		}
+	}
+}
+
 #define REENCODE(font) fprintf(out,"/%s /%s-iso isovec ReEncode\n",font,font)
 
 #ifdef YY_USE_PROTOS
@@ -3937,6 +3935,7 @@
   char *lnumber = NULL;
   char *function = NULL;
   char *nonlatin = NULL;
+  char *pflag = NULL;
 
   out = stdout;
   first = NULL;
@@ -3984,7 +3983,7 @@
 					      argv[i]);
 				      exit(0);
 				    }                                           break;
-			case 'p': if (!strcmp(argv[i], "Letter")) letter = 1;	break;
+			case 'p': DUP(pflag,      argv[i]);			break;
 			case 't': tab = abs(atoi (argv[i])); 			break;
 			case 'F': DUP(dftfont,    argv[i]);		        break;
 			case 'P': DUP(preproc,    argv[i]);		        break;
@@ -4078,6 +4077,8 @@
       nonlatin_text = 1;
     }
 
+  getpaper(pflag);
+
   fprintf(out, "%%!PS-Adobe-2.0\n%%%%Creator: c2ps version %s\n", VERSION);
   fprintf(out, "%%%%Orientation: %s\n", (ppl == 2) ? "Landscape" : "Portrait");
   fprintf(out, "%%%%Pages: (atend)\n");
@@ -4089,7 +4090,7 @@
     fprintf(out, " %s %s %s %s %s %s",
 	    keyword, strings, type, preproc, comment, function);
   fprintf(out, "\n%%%%DocumentMedia: %s\n%%%%EndComments\n\n",
-	    (letter) ? "Letter 612 792" : "A4 595 842");
+	    (strncasecmp(pspec.name, "letter", 7) == 0) ? "Letter 612 792" : "A4 595 842");
   if (iso)
     {
       fprintf(out, ISO);
