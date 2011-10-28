--- src/mod/loggers/mod_logfile/mod_logfile.c.orig	2011-02-02 11:08:44.000000000 -0500
+++ src/mod/loggers/mod_logfile/mod_logfile.c	2011-02-02 11:09:38.000000000 -0500
@@ -94,7 +94,7 @@
 	flags |= SWITCH_FOPEN_WRITE;
 	flags |= SWITCH_FOPEN_APPEND;
 
-	stat = switch_file_open(&afd, profile->logfile, flags, SWITCH_FPROT_UREAD | SWITCH_FPROT_UWRITE | SWITCH_FPROT_WREAD, module_pool);
+	stat = switch_file_open(&afd, profile->logfile, flags, SWITCH_FPROT_UREAD | SWITCH_FPROT_UWRITE | SWITCH_FPROT_GREAD | SWITCH_FPROT_WREAD, module_pool);
 	if (stat != SWITCH_STATUS_SUCCESS) {
 		return SWITCH_STATUS_FALSE;
 	}
