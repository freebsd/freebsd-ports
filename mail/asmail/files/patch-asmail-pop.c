$FreeBSD$

--- pop.c.orig	Thu Apr 13 19:08:02 2000
+++ pop.c	Sat May  5 04:06:47 2001
@@ -196,7 +196,8 @@
 {
     SOCKET *sock;
     int sd, i, port = 0, type;
-    char server[100], user[100], password[100], mailbox[100];
+    char server[100], user[100], password[100];
+    char mailbox[100] = "INBOX";	/* default mailbox */
     char *pnt;
     static int InDuty = 0;
 
@@ -229,18 +230,19 @@
         return -1;
     }
     
-    /* optional portnumber */
+    /* optional portnumber and mailbox for IMAP4 */
     pnt += strlen(password) + 1;
-    if (sscanf(pnt, "%d", &port) != 1)
-       switch (type) {
-          case TYPE_POP: port = DEFAULTPORT; break;
-          case TYPE_IMAP: port = DEFAULTIMAPPORT; break;
-       }
-
-    /* optional mailboxname for IMAP */
-    if (type == TYPE_IMAP)
-       if (sscanf(pnt, "%100s", &mailbox) != 1)
-          strcpy(mailbox, "INBOX");
+    switch (type) {
+	case TYPE_POP:
+	    port = DEFAULTPORT;
+	    sscanf(pnt, "%d", &port);
+	    break;
+	case TYPE_IMAP:
+	    port = DEFAULTIMAPPORT;
+	    if (sscanf(pnt, "%d %100s", &port, &mailbox) == 0)
+		sscanf(pnt, "%100s", &mailbox);
+	    break;
+    }
 
     /* Feb. 17 2000: Removed toupper() of mailbox names.
      * Some IMAP servers seem to have troubles with case-insensitive
