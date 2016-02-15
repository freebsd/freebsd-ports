--- foomaticrip.c.orig	2012-07-02 14:50:46 UTC
+++ foomaticrip.c
@@ -180,7 +180,7 @@ char cupsfilterpath[PATH_MAX] = "/usr/lo
                                 "/opt/cups/filter:"
                                 "/usr/lib/cups/filter";
 
-char modern_shell[64] = "/bin/bash";
+char modern_shell[64] = "/bin/sh";
 
 void config_set_option(const char *key, const char *value)
 {
@@ -1061,7 +1061,7 @@ int print_file(const char *filename, int
 		   Ghostscript is not available. */
 		if (spooler == SPOOLER_CUPS)
 		  snprintf(pdf2ps_cmd, PATH_MAX,
-			   "pdftops '%s' '%s' '%s' '%s' '%s' '%s'",
+			   "/usr/local/libexec/cups/filter/pdftops '%s' '%s' '%s' '%s' '%s' '%s'",
 			   job->id, job->user, job->title, "1", job->optstr->data,
 			   filename);
 		else
@@ -1197,7 +1197,8 @@ int main(int argc, char** argv)
         debug = 1;
 
     if (debug) {
-	int fd = mkstemp (LOG_FILE "-XXXXXX.log");
+	sprintf(tmp, "%s-XXXXXX.log", LOG_FILE);
+	int fd = mkstemps (tmp, 4);
 	if (fd != -1)
 	    logh = fdopen(fd, "w");
 	else
