--- metamail/mailto.c.orig	1994-02-09 20:30:26 UTC
+++ metamail/mailto.c
@@ -37,6 +37,8 @@ STILL NEED TO DO/SUPPORT:
 */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #include <config.h>
 #include <pwd.h>
@@ -60,7 +62,6 @@ extern char *getenv();
 #include <unistd.h>
 #endif
 
-extern char *malloc(), *realloc(), *index(), *getmyname();
 struct mailpart *CreateNewPart();
 
 /* The main data structure for the multiple parts of the mail */
@@ -570,6 +571,7 @@ char **argv;
         if (isupper(*sdum)) *sdum = tolower(*sdum);
     }
     if (strcmp(CharacterSet, "us-ascii")
+	 && strcmp(CharacterSet, "koi8-r")
          && strncmp(CharacterSet, "iso-8859-", 9)) {
         fprintf(stderr, "mailto:  Unsupported character set: %s\n", CharacterSet);
         exit(-1);
@@ -1072,7 +1074,7 @@ struct mailpart *FirstPart;
 #endif
     }
     fprintf(fp, "Message-ID: %s\n", newid());
-    if (!FirstPart) return; /* empty body */
+    if (!FirstPart) return(0); /* empty body */
     if (FirstPart->next) {
         char boundary[120];
 #ifdef AMIGA
@@ -1130,6 +1132,7 @@ struct mailpart *part;
         if (part->isrich) {
             if (strcmp(CharacterSet, "us-ascii")
                  && (strncmp(CharacterSet, "iso-8859-", 9) 
+		     && strcmp(CharacterSet, "koi8-r")
                       || part->encoding_type_needed != ENC_NONE)) {
                 fprintf(fp, "Content-type: text/richtext; charset=\"%s\"\n", CharacterSet);
             } else {
@@ -1140,6 +1143,7 @@ struct mailpart *part;
             WriteCtypeNicely(fp, part->content_type);
             if (strcmp(CharacterSet, "us-ascii")
                  && (strncmp(CharacterSet, "iso-8859-", 9) 
+		     && strcmp(CharacterSet, "koi8-r")
                       || part->encoding_type_needed != ENC_NONE)) {
                 fprintf(fp, "; charset=\"%s\"\n", CharacterSet);
             } else fputs("\n", fp);
@@ -1346,7 +1350,7 @@ int EightBitMode, RightToLeftMode;
         }
         part->isrich = 1;
         PartEndsWithNewline=1;
-        return;
+        return(0);
     }
     InNewLineSequence = 0;
     if (RightToLeftMode) {
@@ -1745,6 +1749,7 @@ CreateNewPart() {
     }
     printf("\n\nEnter your choice as a number from 0 to %d: ", i);
     fflush(stdout);
+    *LineBuf = '\0';
     fgets(LineBuf, sizeof(LineBuf), stdin);
     ans = atoi(LineBuf);
     if (ans == 0 || ans == 1) {
@@ -1752,8 +1757,9 @@ CreateNewPart() {
         FILE *fpi, *fpo;
 	printf("\nIf you want to include non-textual data from a file, enter the file name.\nTo include the output of a command, enter \"|\" followed by the command.\nIf you do not want to include anything, just press ENTER (RETURN).\n> ");
         fflush(stdout);
+        *CTLineBuf = '\0';
         fgets(CTLineBuf, sizeof(CTLineBuf), stdin);
-        sdum = CTLineBuf+strlen(CTLineBuf) -1;
+        sdum = *CTLineBuf ? CTLineBuf+strlen(CTLineBuf) -1 : CTLineBuf;
         while (sdum >= CTLineBuf && isspace((unsigned char) *sdum)) {
             *sdum = '\0';
             --sdum;
@@ -1791,7 +1797,10 @@ CreateNewPart() {
                 int ct;
                 printf("\nEnter the MIME Content-type value for the data from file %s\n    (type '?' for a list of locally-valid content-types): ", sdum);
                 fflush(stdout);
-                gets(LineBuf);
+                *LineBuf = '\0';
+                fgets(LineBuf, sizeof(LineBuf), stdin);
+                if (*LineBuf)
+                    LineBuf[strlen(LineBuf) - 1] = '\0';
                 if (index(LineBuf, '/')) {
                     char lc[100], *s, AnsBuf[100];
                     strcpy(lc, LineBuf);
@@ -1809,7 +1818,7 @@ CreateNewPart() {
                     }
                     if (mc) break;
                     printf("The MIME content-type '%s' is not listed in your local mailcap files,\nand may not be a valid MIME type.  Do you want to use it anyway [no] ? ", LineBuf);
-                    s = gets(AnsBuf);
+                    s = fgets(AnsBuf, sizeof(AnsBuf), stdin);
                     while (s && *s && isspace((unsigned char) *s)) ++s;
                     if (s && (*s == 'y' || *s == 'Y')) break;
                     continue;
@@ -2109,7 +2118,7 @@ int UseVisual;
         fpout = fopen(FirstPart->filename, "a");
         free(CmdBuf);
         free(CmdBuf2);
-        return;
+        return(0);
     }
     lastmp = mp = FirstPart;
     while (mp) {
@@ -2137,6 +2146,7 @@ int UseVisual;
             printf("2: %s\n", CmdBuf);
             printf("\n\nEnter 1 or 2, or 0 to not edit it: ");
             fflush(stdout);
+            *LineBuf = '\0';
             fgets(LineBuf, sizeof(LineBuf), stdin);
             ans = atoi(LineBuf);
         } else ans = 2;
@@ -2221,7 +2231,7 @@ int IsAndrew;
     int LineAlloced = 0, LineCount = 0;
 
     fp = fopen(fname, "r");
-    if (!fp) return;
+    if (!fp) return(0);
     do {
         LineBuf=NextAliasLine(LineBuf, &LineAlloced, &LineCount, fp, IsAndrew);
         if (LineCount == 0) continue;
@@ -2310,7 +2320,7 @@ char *aliasline;
         if (s != s2) printf("mailto: ignoring bad alias line in init file: %s\n", aliasline);
         free(s);
         free(tmpalias);
-        return;
+        return(0);
     }
     *s2++ = '\0';
     tmpalias->shortname = s;
@@ -2364,7 +2374,7 @@ char *hdr;
 {
     char *firstnonascii, *firstascii;
 
-    if (!s) return;
+    if (!s) return(0);
     firstnonascii=firstbad(s);
     if (firstnonascii) {
         if (!strcmp(CharacterSet, "us-ascii")) {
@@ -2454,7 +2464,7 @@ char *hdr;
 /*        if (!lc2strcmp(name, tmpalias->shortname)) { */
             *end = savechar;
             EmitAddresses(fp, tmpalias->longname, hdr);
-            return;
+            return(0);
         }
     }
     *end = savechar;
