--- foomaticrip.c.orig	2012-07-02 10:50:46.000000000 -0400
+++ foomaticrip.c	2014-05-19 10:28:46.588515788 -0400
@@ -180,7 +180,7 @@
                                 "/opt/cups/filter:"
                                 "/usr/lib/cups/filter";
 
-char modern_shell[64] = "/bin/bash";
+char modern_shell[64] = "/bin/sh";
 
 void config_set_option(const char *key, const char *value)
 {
@@ -1061,7 +1061,7 @@
 		   Ghostscript is not available. */
 		if (spooler == SPOOLER_CUPS)
 		  snprintf(pdf2ps_cmd, PATH_MAX,
-			   "pdftops '%s' '%s' '%s' '%s' '%s' '%s'",
+			   "%%LOCALBASE%%/libexec/cups/filter/pdftops '%s' '%s' '%s' '%s' '%s' '%s'",
 			   job->id, job->user, job->title, "1", job->optstr->data,
 			   filename);
 		else
@@ -1197,7 +1197,8 @@
         debug = 1;
 
     if (debug) {
-	int fd = mkstemp (LOG_FILE "-XXXXXX.log");
+	sprintf(tmp, "%s-XXXXXX.log", LOG_FILE);
+	int fd = mkstemps (tmp, 4);
 	if (fd != -1)
 	    logh = fdopen(fd, "w");
 	else
