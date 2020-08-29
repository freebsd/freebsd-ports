--- filan.c.orig	2020-01-01 13:02:06 UTC
+++ filan.c
@@ -30,7 +30,7 @@ static int filan_streams_analyze(int fd, FILE *outfile
 
 /* dirty workaround so we dont get an error on AIX when being linked with
    libwrap */
-int allow_severity, deny_severity;
+//int allow_severity, deny_severity;
 
 /* global variables for configuring filan */
 bool filan_followsymlinks;
