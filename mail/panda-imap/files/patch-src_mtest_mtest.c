--- src/mtest/mtest.c.orig	Sat May 29 08:07:06 1999
+++ src/mtest/mtest.c	Sun Dec 19 15:29:29 1999
@@ -95,6 +95,7 @@
 void status (MAILSTREAM *stream);
 void prompt (char *msg,char *txt);
 void smtptest (long debug);
+char *safegets(char *buf);
 
 /* Main program - initialization */
 
@@ -528,7 +529,7 @@
 void prompt (char *msg,char *txt)
 {
   printf ("%s",msg);
-  gets (txt);
+  safegets (txt);
 }
 
 /* Interfaces to C-client */
@@ -713,7 +714,7 @@
   puts (" Msg (end with a line with only a '.'):");
   body->type = TYPETEXT;
   *text = '\0';
-  while (gets (line)) {
+  while (safegets (line)) {
     if (line[0] == '.') {
       if (line[1] == '\0') break;
       else strcat (text,".");
@@ -744,4 +745,18 @@
   else puts ("[Can't open connection to any server]");
   mail_free_envelope (&msg);
   mail_free_body (&body);
+}
+
+char *safegets(char *buf) {
+ char *p;
+
+ if (!fgets(buf, MAILTMPLEN, stdin)) {
+  return NULL;
+ }
+
+ if ((p = strchr(buf, '\n')) != NULL) {
+  *p = '\0';
+ }
+
+ return buf;
 }
