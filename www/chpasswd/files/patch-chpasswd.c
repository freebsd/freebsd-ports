--- chpasswd.c.orig	Fri Apr 11 01:54:02 2003
+++ chpasswd.c	Wed Sep 22 15:46:47 2004
@@ -23,6 +23,16 @@
 static void vrfyauth(IpAuth,PwdLogFile,PwdFile,SmtpUser,SmtpSubject);
 eperror(s);
 
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
