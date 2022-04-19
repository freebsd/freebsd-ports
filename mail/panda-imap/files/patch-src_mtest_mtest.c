--- src/mtest/mtest.c.orig	2022-04-17 00:12:02 UTC
+++ src/mtest/mtest.c
@@ -79,6 +79,7 @@ void display_body (BODY *body,char *pfx,long i);
 void status (MAILSTREAM *stream);
 void prompt (char *msg,char *txt);
 void smtptest (long debug);
+char *safegets(char *buf);
 
 /* Main program - initialization */
 
@@ -603,7 +604,7 @@ void status (MAILSTREAM *stream)
 void prompt (char *msg,char *txt)
 {
   printf ("%s",msg);
-  gets (txt);
+  safegets (txt);
 }
 
 /* Interfaces to C-client */
@@ -787,7 +788,7 @@ void smtptest (long debug)
   puts (" Msg (end with a line with only a '.'):");
   body->type = TYPETEXT;
   *text = '\0';
-  while (gets (line)) {
+  while (safegets (line)) {
     if (line[0] == '.') {
       if (line[1] == '\0') break;
       else strcat (text,".");
@@ -818,4 +819,18 @@ void smtptest (long debug)
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
