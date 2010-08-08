From 0c551c6ed29922b1827a2adceac58e04ae2f37ce Mon Sep 17 00:00:00 2001
From: Andrew Borodin <aborodin@vmail.ru>
Date: Wed, 19 May 2010 10:54:22 +0400
Subject: [PATCH 1/1] Fixed build with --disable-charset option. Minor optimization.

Signed-off-by: Andrew Borodin <aborodin@vmail.ru>
---
 src/ext.c |   20 ++++++++++++++++----
 1 files changed, 16 insertions(+), 4 deletions(-)

index 81661c5..89f216d 100644
--- src/ext.c.orig
+++ src/ext.c
@@ -48,8 +48,10 @@
 #include "execute.h"
 #include "history.h"
 #include "layout.h"
+#ifdef HAVE_CHARSET
 #include "charsets.h"		/* get_codepage_index */
 #include "selcodepage.h"	/* do_set_codepage */
+#endif
 #include "ext.h"
 
 /* If set, we execute the file command to check the file type */
@@ -370,6 +372,7 @@ get_file_type_local (const char *filename, char *buf, int buflen)
     return ret;
 }
 
+#ifdef HAVE_CHARSET
 /*
  * Run the "enca" command on the local file.
  * Return 1 if the data is valid, 0 otherwise, -1 for fatal errors.
@@ -392,6 +395,7 @@ get_file_encoding_local (const char *filename, char *buf, int buflen)
 
     return ret;
 }
+#endif /* HAVE_CHARSET */
 
 /*
  * Invoke the "file" command on the file and match its output against PTR.
@@ -416,7 +420,10 @@ regex_check_type (const char *filename, const char *ptr, int *have_type)
     if (*have_type == 0) {
 	char *realname;		/* name used with "file" */
 	char *localfile;
+
+#ifdef HAVE_CHARSET
 	int got_encoding_data;
+#endif /* HAVE_CHARSET */
 
 	/* Don't repeate even unsuccessful checks */
 	*have_type = 1;
@@ -427,12 +434,11 @@ regex_check_type (const char *filename, const char *ptr, int *have_type)
 
 	realname = localfile;
 
+#ifdef HAVE_CHARSET
 	got_encoding_data = is_autodetect_codeset_enabled
 		? get_file_encoding_local (localfile, encoding_id, sizeof (encoding_id))
 		: 0;
 
-	mc_ungetlocalcopy (filename, localfile, 0);
-
 	if (got_encoding_data > 0) {
 	    char *pp;
 	    int cp_id;
@@ -447,19 +453,25 @@ regex_check_type (const char *filename, const char *ptr, int *have_type)
 
 	    do_set_codepage (cp_id);
 	}
+#endif /* HAVE_CHARSET */
+
+	mc_ungetlocalcopy (filename, localfile, 0);
 
 	got_data = get_file_type_local (localfile, content_string, sizeof (content_string));
 
 	if (got_data > 0) {
 	    char *pp;
+	    size_t real_len;
 
 	    pp = strchr (content_string, '\n');
 	    if (pp != NULL)
 		*pp = '\0';
 
-	    if (strncmp (content_string, realname, strlen (realname)) == 0) {
+	    real_len = strlen (realname);
+
+	    if (strncmp (content_string, realname, real_len) == 0) {
 		/* Skip "realname: " */
-		content_shift = strlen (realname);
+		content_shift = real_len;
 		if (content_string[content_shift] == ':') {
 		    /* Solaris' file prints tab(s) after ':' */
 		    for (content_shift++;
-- 
1.6.5.GIT

