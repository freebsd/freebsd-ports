--- chpasswd.c.orig	2005-05-09 13:05:08.000000000 +0000
+++ chpasswd.c	2007-11-08 15:10:11.000000000 +0000
@@ -282,7 +282,7 @@
 }
 
 
-static int
+int
 htoi(s)
         unsigned char   *s;
 {
@@ -664,6 +664,16 @@
 }
 
 
+void getword(char *, char *, char);
+void Herror(char *);
+void Hmsg(char *);
+void putline(FILE *, char *);
+void Changed(char *, char *, char *, char *, char *, char *, char *);
+void NotFound(char *, char *, char *, char *, char *, char *, char *);
+void rulefail(char *, char *, char *);
+static void strip_latin(char *);
+void sendmail(char *, char *, char *);
+
 main(argc, argv)
     int             argc;
     char           *argv[];
