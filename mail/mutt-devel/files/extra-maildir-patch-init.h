--- init.h.orig	Tue Jul 18 04:46:46 2000
+++ init.h	Tue Feb 20 20:46:56 2001
@@ -860,6 +860,15 @@
   { "mailcap_sanitize",	DT_BOOL, R_NONE, OPTMAILCAPSANITIZE, 1 },
   /*
   ** .pp
+  ** This variable specifies that maildir tmp directories
+  ** should have 36 hours non-accessed files deleted
+  ** This is measured in minutes, hence 36*60 minutes (36 hours)
+  ** (default: off)
+  */
+  { "maildir_tmp_clean", DT_BOOL, R_NONE, OPTCLEANMTMP, 0 },
+  { "maildir_tmp_clean_interval", DT_NUM, R_NONE, UL &MaildirTmpClnInterval, 36*60 },
+  /*
+  ** .pp
   ** If set, mutt will restrict possible characters in mailcap % expandos
   ** to a well-defined set of safe characters.  This is the safe setting,
   ** but we are not sure it doesn't break some more advanced MIME stuff.
