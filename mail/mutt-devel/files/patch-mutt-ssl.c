--- mutt_ssl.c.orig	2009-06-10 07:08:29.000000000 +0200
+++ mutt_ssl.c	2010-05-03 10:45:21.000000000 +0200
@@ -652,7 +652,7 @@
   char *buf = NULL;
   int bufsize;
   /* needed to get the DNS subjectAltNames: */
-  STACK *subj_alt_names;
+  STACK_OF(GENERAL_NAME) *subj_alt_names;
   int subj_alt_names_count;
   GENERAL_NAME *subj_alt_name;
   /* did we find a name matching hostname? */
