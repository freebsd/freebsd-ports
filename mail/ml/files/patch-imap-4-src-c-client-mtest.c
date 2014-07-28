--- ../imap-4/src/c-client/mtest.c.orig        Sun Jun 13 16:51:38 1999
+++ ../imap-4/src/c-client/mtest.c     Sun Jun 13 16:54:03 1999
@@ -479,7 +479,7 @@
 void prompt (char *msg,char *txt)
 {
   printf ("%s",msg);
-  gets (txt);
+  fgets (txt, (8 * MAILTMPLEN), stdin);
 }
 
 /* Interfaces to C-client */
@@ -664,7 +664,7 @@
   puts (" Msg (end with a line with only a '.'):");
   body->type = TYPETEXT;
   *text = '\0';
-  while (gets (line)) {
+  while (fgets (line, MAILTMPLEN, stdin)) {
     if (line[0] == '.') {
       if (line[1] == '\0') break;
       else strcat ((char *) text,".");
