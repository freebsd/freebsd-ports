--- metamail/metamail.c.orig	Thu Feb 17 02:57:19 1994
+++ metamail/metamail.c	Mon Dec 18 11:46:22 2006
@@ -20,6 +20,8 @@
 
  ******************************************************* */
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -83,7 +85,7 @@
 #define MAX_FILE_NAME_SIZE 256
 #define WRITE_BINARY	"w"
 #else /* AMIGA */
-extern char **environ, *gets();
+extern char **environ;
 #define CATCOMMAND  "cat"
 #define CATTEMPLATE "cat %s"
 #define METAMAIL    "metamail"
@@ -100,6 +102,7 @@
 #define CMDSIZE 1200 /* Maximum size of command to execute */
 
 #define LINE_BUF_SIZE       2000
+#if 0
 #ifndef MICROSOFT
 extern char *malloc();
 extern char *realloc();
@@ -107,10 +110,12 @@
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
@@ -540,6 +545,7 @@
                     ans = 2;
                 } else {
                     printf("\nWhat do you want to do with the %s data?\n1 -- See it as text\n2 -- Write it to a file\n3 -- Just skip it\n\n", octetstream ? "raw" : ContentType);
+                    *Fname = '\0';
                     fgets(Fname, sizeof(Fname), stdin);
                     ans = atoi(Fname);
                 }
@@ -554,8 +560,10 @@
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
@@ -579,10 +587,12 @@
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
@@ -1202,9 +1212,9 @@
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
@@ -1823,8 +1833,9 @@
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
@@ -2022,7 +2033,8 @@
     if (lc2strcmp(charset, PrevCharset)) {
         char *s2, *charsetinuse;
 
-        strcpy(PrevCharset, charset);
+        strncpy(PrevCharset, charset, sizeof(PrevCharset));
+        PrevCharset[sizeof(PrevCharset) - 1] = '\0';
         for (s2=PrevCharset; *s2; ++s2) {
             if (isupper((unsigned char) *s2)) *s2 = tolower((unsigned char) *s2);
         }
@@ -2032,7 +2044,7 @@
         }
     }
     if (ecode == ENCODING_NONE) {
-        printf(txt+1);
+        printf("%s", txt+1);
     } else {
         /* What follows is REALLY bogus, but all my encoding stuff is pipe-oriented right now... */
         MkTmpFileName(TmpFile);
