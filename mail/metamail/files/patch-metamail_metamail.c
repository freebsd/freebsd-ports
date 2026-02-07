--- metamail/metamail.c.orig	1994-02-17 01:57:19 UTC
+++ metamail/metamail.c
@@ -20,6 +20,8 @@ WITHOUT ANY EXPRESS OR IMPLIED WARRANTIE
 
  ******************************************************* */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -46,8 +48,8 @@ extern char *mktemp(char *);
 #include <signal.h>
 
 #ifndef AMIGA
-#ifdef SYSV
-#include <termio.h>
+#if 1
+#include <termios.h>
 #include <unistd.h>
 #else /* SYSV */
 #include <sgtty.h>
@@ -83,7 +85,7 @@ extern char *MkRmScript();
 #define MAX_FILE_NAME_SIZE 256
 #define WRITE_BINARY	"w"
 #else /* AMIGA */
-extern char **environ, *gets();
+extern char **environ;
 #define CATCOMMAND  "cat"
 #define CATTEMPLATE "cat %s"
 #define METAMAIL    "metamail"
@@ -100,6 +102,7 @@ extern char **environ, *gets();
 #define CMDSIZE 1200 /* Maximum size of command to execute */
 
 #define LINE_BUF_SIZE       2000
+#if 0
 #ifndef MICROSOFT
 extern char *malloc();
 extern char *realloc();
@@ -107,10 +110,12 @@ extern char *realloc();
 extern char *getenv();
 extern char *index();
 extern char *rindex();
+extern FILE *popen();
+#endif
+
 char fileToDelete[MAX_FILE_NAME_SIZE];
 
 char *FindParam();
-extern FILE *popen();
 static char *nomem = "Out of memory!";
 static char *mmversion = MM_VERSTRING;
 static char *NoAskDefault = "text,text/plain,text/richtext";
@@ -540,6 +545,7 @@ int nestingdepth;
                     ans = 2;
                 } else {
                     printf("\nWhat do you want to do with the %s data?\n1 -- See it as text\n2 -- Write it to a file\n3 -- Just skip it\n\n", octetstream ? "raw" : ContentType);
+                    *Fname = '\0';
                     fgets(Fname, sizeof(Fname), stdin);
                     ans = atoi(Fname);
                 }
@@ -554,8 +560,10 @@ int nestingdepth;
                             needname = 0;
                             printf("Please enter the name of a file to which the data should be written\n(Default: %s) > ", suggestedname);
                             fflush(stdout);
+                            *Fname = '\0';
                             fgets(Fname, sizeof(Fname), stdin);
-                            Fname[strlen(Fname) - 1] = '\0'; /* bogus newline */
+                            if (*Fname)
+                                Fname[strlen(Fname) - 1] = '\0'; /* bogus newline */
 #if !defined(AMIGA) && !defined(MSDOS)
                             if (!Fname[0]) strcpy(Fname, suggestedname);
                             if (Fname[0] == '~' && Fname[1] == '/') {
@@ -579,10 +587,12 @@ int nestingdepth;
                                 int overwriteans = -1;
                                 do {
                                     printf("File %s exists.  Do you want to overwrite it (y/n) ?\n", Fname);
-                                    s = gets(AnsBuf);
+                                    *AnsBuf = '\0';
+                                    s = fgets(AnsBuf, sizeof(AnsBuf), stdin);
                                     if (!s) {
                                         overwriteans = 0;
                                     } else {
+                                        s[strlen(s) - 1] = '\0';
                                         while (s && *s && isspace((unsigned char) *s)) ++s;
                                         if (*s == 'y' || *s == 'Y' || !*s || *s == '\n') {
                                             overwriteans = 1;
@@ -1202,9 +1212,9 @@ char *SquirrelFile;
     fprintf(outfp, "Content-type: %s", ContentType);
     for (j=0; j<CParamsUsed; ++j) {
         fprintf(outfp, " ; ");
-        fprintf(outfp, CParams[j]);
+        fprintf(outfp, "%s", CParams[j]);
         fprintf(outfp, " = ");
-        fprintf(outfp, CParamValues[j]);
+        fprintf(outfp, "%s", CParamValues[j]);
     }
     fprintf(outfp, "\n\n"); 
     TranslateInputToOutput(InputFP, outfp, EncodingCode, ContentType);
@@ -1823,8 +1833,9 @@ char *ctype, *progname, *label;
         } else {
             printf("This message contains '%s'-format data.\nDo you want to view it using the '%s' command (y/n) [y] ? ", ctype, ShortCommand(progname));
         }
-        s = gets(AnsBuf);
+        s = fgets(AnsBuf, sizeof(AnsBuf), stdin);
         if (!s) return(0); /* EOF */
+        s[strlen(s) - 1] = '\0';
 	while (s && *s && isspace((unsigned char) *s)) ++s;
 	if (*s == 'y' || *s == 'Y' || !*s || *s == '\n') return(1);
 	if (*s == 'n' || *s == 'N' || *s == 'q' || *s == 'Q') {
@@ -1915,18 +1926,18 @@ char *hdr;
             if (!strcmp(KeyHeadList[numkeys], "*")
                  || !lc2strncmp(hdr, KeyHeadList[numkeys], len)) {
 		if (!KeyKeep) phead(hdr);
-		return;
+		return(0);
             }
         }
 	if (KeyKeep) phead(hdr);
-	return;
+	return(0);
     }
     if (!strncmp(hdr, "From ", 5) || !strncmp(hdr, ">From ", 6)) {
 	for (numkeys = 0; KeyHeadList[numkeys]; ++numkeys) {
 	    if (!strcmp(KeyHeadList[numkeys], "*")
 		 || !lc2strncmp(">from", KeyHeadList[numkeys], 5)) {
 		if (!KeyKeep) phead(hdr);
-		return;
+		return(0);
 	    }
 	}
 	if (KeyKeep) phead(hdr);
@@ -2022,7 +2033,8 @@ int ShowLeadingWhitespace;
     if (lc2strcmp(charset, PrevCharset)) {
         char *s2, *charsetinuse;
 
-        strcpy(PrevCharset, charset);
+        strncpy(PrevCharset, charset, sizeof(PrevCharset));
+        PrevCharset[sizeof(PrevCharset) - 1] = '\0';
         for (s2=PrevCharset; *s2; ++s2) {
             if (isupper((unsigned char) *s2)) *s2 = tolower((unsigned char) *s2);
         }
@@ -2032,7 +2044,7 @@ int ShowLeadingWhitespace;
         }
     }
     if (ecode == ENCODING_NONE) {
-        printf(txt+1);
+        printf("%s", txt+1);
     } else {
         /* What follows is REALLY bogus, but all my encoding stuff is pipe-oriented right now... */
         MkTmpFileName(TmpFile);
@@ -2375,8 +2387,8 @@ char *Prefix;
 
 int HasSavedTtyState=0;
 #if !defined(AMIGA) && !defined(MSDOS)
-#ifdef SYSV
-static struct termio MyTtyStateIn, MyTtyStateOut;
+#if 1
+static struct termios MyTtyStateIn, MyTtyStateOut;
 #else
 static struct sgttyb MyTtyStateIn, MyTtyStateOut;
 #endif
@@ -2385,9 +2397,9 @@ static struct sgttyb MyTtyStateIn, MyTty
 SaveTtyState() {
     /* Bogus -- would like a good portable way to reset the terminal state here */
 #if !defined(AMIGA) && !defined(MSDOS)
-#ifdef SYSV
-    ioctl(fileno(stdin), TCGETA, &MyTtyStateIn);
-    ioctl(fileno(stdout), TCGETA, &MyTtyStateOut);
+#if 1
+    tcgetattr(fileno(stdin), &MyTtyStateIn);
+    tcgetattr(fileno(stdout), &MyTtyStateOut);
 #else
     gtty(fileno(stdin), &MyTtyStateIn);
     gtty(fileno(stdout), &MyTtyStateOut);
@@ -2398,10 +2410,10 @@ SaveTtyState() {
 
 RestoreTtyState() {
 #if !defined(AMIGA) && !defined(MSDOS)
-#ifdef SYSV
+#if 1
     if (HasSavedTtyState) {
-        ioctl(fileno(stdout), TCSETA, &MyTtyStateOut);
-        ioctl(fileno(stdin), TCSETA, &MyTtyStateIn);
+        tcsetattr(fileno(stdout), TCSANOW, &MyTtyStateOut);
+        tcsetattr(fileno(stdin), TCSANOW, &MyTtyStateIn);
     }
 #else
     if (HasSavedTtyState) {
@@ -2660,7 +2672,7 @@ PauseForUser() {
     char Buf[100];
 #endif
 
-    if (DefinitelyNotTty || MustNotBeTty) return;	
+    if (DefinitelyNotTty || MustNotBeTty) return(0);	
 #if defined(MSDOS) || defined(AMIGA)
     printf("Press RETURN to go on\n");
     gets(Buf);
@@ -2681,15 +2693,15 @@ PauseForUser() {
 
 StartRawStdin() {
 #if !defined(AMIGA) && !defined(MSDOS)
-#ifdef SYSV
-    struct termio   orterm, fterm;
-    ioctl(0, TCGETA, &orterm);	/* get current (i.e. cooked) termio */
+#if 1
+    struct termios   orterm, fterm;
+    tcgetattr(0, &orterm);
     fterm = orterm;		/* get termio to modify */
 
     fterm.c_lflag &= ~ICANON;	/* clear ICANON giving raw mode */
     fterm.c_cc[VMIN] = 1;	/* set MIN char count to 1 */
     fterm.c_cc[VTIME] = 0;	/* set NO time limit */
-    return ioctl(0, TCSETAW, &fterm);	/* modify termio for raw mode */
+    return tcsetattr(0, TCSANOW, &fterm);	/* modify termio for raw mode */
 #else
     struct sgttyb ts;
     gtty(fileno(stdin), &ts);
