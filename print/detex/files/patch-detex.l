--- detex.l.orig	2012-12-03 11:22:59.000000000 +0100
+++ detex.l	2012-12-03 11:23:02.000000000 +0100
@@ -99,6 +99,18 @@
 int	fSpace = 0;			/* flag to replace \cs with space */
 int	fForcetex = 0;			/* flag to inhibit latex mode */
 
+int  BeginEnv (char *);
+int  EndEnv (char *);
+void IncludeFile (char *);
+void AddInclude (char *);
+void InputFile (char *);
+void SetInputPaths ();
+void ErrorExit (char *);
+void Warning (char *, char *);
+void SetEnvIgnore (char *);
+int  SeparateList (char *, char *[], char, int);
+int  InList (char *);
+
 #ifdef FLEX_SCANNER
 /* flex has contexts for buffers that need to be switched when file changes
  * otherwise output contains imported files in reverse order.  Weird, but
@@ -368,9 +380,8 @@
 **	If no input files are specified on the command line, process stdin.
 ******/
 
-main(cArgs,rgsbArgs)
-int	cArgs;
-char	*rgsbArgs[];
+int
+main(int cArgs, char *rgsbArgs[])
 {
 	char	*pch, *sbEnvList = DEFAULTENV, sbBadOpt[2];
 	FILE	*TexOpen();
@@ -477,6 +488,7 @@
 **	return the termination signal for lex.
 ******/
 
+int
 yywrap()
 {
 	(void)fclose(yyin);
@@ -516,8 +528,8 @@
 **	sbEnvList.
 ******/
 
-SetEnvIgnore(sbEnvList)
-char	*sbEnvList;
+void
+SetEnvIgnore(char *sbEnvList)
 {
 	char *sb;
 
@@ -533,8 +545,8 @@
 **	is, sbCurrentEnv is set to sbEnv.
 ******/
 
-BeginEnv(sbEnv)
-char	*sbEnv;
+int
+BeginEnv(char *sbEnv)
 {
 	int	i;
 
@@ -551,8 +563,8 @@
 ** EndEnv -- checks to see if sbEnv is the current environment being ignored.
 ******/
 
-EndEnv(sbEnv)
-char	*sbEnv;
+int
+EndEnv(char *sbEnv)
 {
 	if (!fLatex) return(0);
 	if (strcmp(sbEnv, sbCurrentEnv) == 0)
@@ -565,8 +577,8 @@
 **	the sbFile is ignored.
 ******/
 
-InputFile(sbFile)
-char	*sbFile;
+void
+InputFile(char *sbFile)
 {
 	FILE	*TexOpen();
 
@@ -589,8 +601,8 @@
 **	and open sbFile.  If the open fails, the sbFile is ignored.
 ******/
 
-IncludeFile(sbFile)
-char	*sbFile;
+void
+IncludeFile(char *sbFile)
 {
 	FILE	*TexOpen();
 
@@ -615,8 +627,8 @@
 **	If the include list is too long, sbFile is ignored.
 ******/
 
-AddInclude(sbFile)
-char	*sbFile;
+void
+AddInclude(char *sbFile)
 {
 	if (!fFollow)
 	    return;
@@ -631,8 +643,8 @@
 **	no list, all files are assumed to be "in the list".
 ******/
 
-InList(sbFile)
-char	*sbFile;
+int
+InList(char *sbFile)
 {
 	char	*pch, sbBase[MAXPATHLEN];
 	int	i;
@@ -658,6 +670,7 @@
 **	routine does not honor the '//' construct (expand subdirs).
 ******/
 
+void
 SetInputPaths()
 {
 	char *sb, *sbPaths, *getenv();
@@ -698,15 +711,14 @@
 **	ERROR is returned if there are more than csbMax words.
 ******/
 
-SeparateList(sbList, rgsbList, chSep, csbMax)
-char	*sbList, *rgsbList[], chSep;
-int	csbMax;
+int
+SeparateList(char *sbList, char *rgsbList[], char chSep, int csbMax)
 {
 	int	csbList = 0;
 
 	while (sbList && *sbList && csbList < csbMax) {
 	    rgsbList[csbList++] = sbList;
-	    if (sbList = index(sbList, chSep))
+	    if ((sbList = index(sbList, chSep)))
 		*sbList++ = '\0';
 	}
 	return(sbList && *sbList ? ERROR : csbList);
@@ -752,10 +764,12 @@
 	    /* If sbFile ends in .tex then it must be there */
 	    if ((pch = rindex(sbFullPath, '.')) != NULL
 			&& (strcmp(pch, ".tex") == 0))
-		if ((fp = fopen(sbFullPath, "r")) != NULL)
-		    return(fp);
-		else
-		    continue;
+        {
+            if ((fp = fopen(sbFullPath, "r")) != NULL)
+                return(fp);
+            else
+                continue;
+        }
 
 	    /* if .<ext> then try to open it.  the '.' represents   */
 	    /* the beginning of an extension if it is not the first */
@@ -799,8 +813,8 @@
 ** Warning -- print a warning message preceded by the program name.
 ******/
 
-Warning(sb1, sb2)
-char	*sb1, *sb2;
+void
+Warning(char *sb1, char *sb2)
 {
 	(void)fprintf(stderr, "%s: warning: %s %s\n", sbProgName, sb1, sb2);
 }
@@ -810,8 +824,8 @@
 **	Stdout is flushed and detex exits.
 ******/
 
-ErrorExit(sb1)
-char	*sb1;
+void
+ErrorExit(char *sb1)
 {
 	(void)fflush(stdout);
 	(void)fprintf(stderr, "%s: error: %s\n", sbProgName, sb1);
