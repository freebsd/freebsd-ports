--- metamail/mailto.c.orig	Wed Feb  9 21:30:26 1994
+++ metamail/mailto.c	Mon Dec 18 11:46:21 2006
@@ -37,6 +37,8 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #include <config.h>
 #include <pwd.h>
@@ -60,7 +62,6 @@
 #include <unistd.h>
 #endif
 
-extern char *malloc(), *realloc(), *index(), *getmyname();
 struct mailpart *CreateNewPart();
 
 /* The main data structure for the multiple parts of the mail */
@@ -570,6 +571,7 @@
         if (isupper(*sdum)) *sdum = tolower(*sdum);
     }
     if (strcmp(CharacterSet, "us-ascii")
+	 && strcmp(CharacterSet, "koi8-r")
          && strncmp(CharacterSet, "iso-8859-", 9)) {
         fprintf(stderr, "mailto:  Unsupported character set: %s\n", CharacterSet);
         exit(-1);
@@ -1130,6 +1132,7 @@
         if (part->isrich) {
             if (strcmp(CharacterSet, "us-ascii")
                  && (strncmp(CharacterSet, "iso-8859-", 9) 
+		     && strcmp(CharacterSet, "koi8-r")
                       || part->encoding_type_needed != ENC_NONE)) {
                 fprintf(fp, "Content-type: text/richtext; charset=\"%s\"\n", CharacterSet);
             } else {
@@ -1140,6 +1143,7 @@
             WriteCtypeNicely(fp, part->content_type);
             if (strcmp(CharacterSet, "us-ascii")
                  && (strncmp(CharacterSet, "iso-8859-", 9) 
+		     && strcmp(CharacterSet, "koi8-r")
                       || part->encoding_type_needed != ENC_NONE)) {
                 fprintf(fp, "; charset=\"%s\"\n", CharacterSet);
             } else fputs("\n", fp);
@@ -1745,6 +1749,7 @@
     }
     printf("\n\nEnter your choice as a number from 0 to %d: ", i);
     fflush(stdout);
+    *LineBuf = '\0';
     fgets(LineBuf, sizeof(LineBuf), stdin);
     ans = atoi(LineBuf);
     if (ans == 0 || ans == 1) {
@@ -1752,8 +1757,9 @@
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
@@ -1791,7 +1797,10 @@
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
@@ -1809,7 +1818,7 @@
                     }
                     if (mc) break;
                     printf("The MIME content-type '%s' is not listed in your local mailcap files,\nand may not be a valid MIME type.  Do you want to use it anyway [no] ? ", LineBuf);
-                    s = gets(AnsBuf);
+                    s = fgets(AnsBuf, sizeof(AnsBuf), stdin);
                     while (s && *s && isspace((unsigned char) *s)) ++s;
                     if (s && (*s == 'y' || *s == 'Y')) break;
                     continue;
@@ -2137,6 +2146,7 @@
             printf("2: %s\n", CmdBuf);
             printf("\n\nEnter 1 or 2, or 0 to not edit it: ");
             fflush(stdout);
+            *LineBuf = '\0';
             fgets(LineBuf, sizeof(LineBuf), stdin);
             ans = atoi(LineBuf);
         } else ans = 2;
