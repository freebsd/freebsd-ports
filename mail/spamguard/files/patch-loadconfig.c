--- loadconfig.c.orig	2007-05-14 15:19:00 UTC
+++ loadconfig.c
@@ -10,6 +10,25 @@
 
 #include "loadconfig.h"
 
+
+int wcnt;
+int bcnt;
+int pcnt;
+int enable_subj_filt;
+
+char logtype[VALSIZE];
+char logfile[VALSIZE];
+char ignorefile[VALSIZE];
+char highfile[VALSIZE];
+char badmailfile[VALSIZE];
+char hostname[VALSIZE];
+char sysadmin[VALSIZE];
+char statfile[VALSIZE];
+char mail_command[VALSIZE];
+char makemap_command[VALSIZE];
+char qsheff_rules_file[VALSIZE];
+char trim_subj_str[VALSIZE];
+
 extern int errno;
 extern int w;
 extern int b;
