--- loadconfig.h.orig	2007-05-14 15:19:00 UTC
+++ loadconfig.h
@@ -12,23 +12,23 @@ enum {
         VALSIZE = 256
 };
 
-int wcnt;
-int bcnt;
-int pcnt;
-int enable_subj_filt;
+extern int wcnt;
+extern int bcnt;
+extern int pcnt;
+extern int enable_subj_filt;
 
-char logtype[VALSIZE];
-char logfile[VALSIZE];
-char ignorefile[VALSIZE];
-char highfile[VALSIZE];
-char badmailfile[VALSIZE];
-char hostname[VALSIZE];
-char sysadmin[VALSIZE];
-char statfile[VALSIZE];
-char mail_command[VALSIZE];
-char makemap_command[VALSIZE];
-char qsheff_rules_file[VALSIZE];
-char trim_subj_str[VALSIZE];
+extern char logtype[VALSIZE];
+extern char logfile[VALSIZE];
+extern char ignorefile[VALSIZE];
+extern char highfile[VALSIZE];
+extern char badmailfile[VALSIZE];
+extern char hostname[VALSIZE];
+extern char sysadmin[VALSIZE];
+extern char statfile[VALSIZE];
+extern char mail_command[VALSIZE];
+extern char makemap_command[VALSIZE];
+extern char qsheff_rules_file[VALSIZE];
+extern char trim_subj_str[VALSIZE];
 
 void
 loadconfig(const char *);
