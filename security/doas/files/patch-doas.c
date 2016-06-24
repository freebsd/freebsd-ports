--- doas.c.orig	2016-06-22 22:59:03 UTC
+++ doas.c
@@ -324,7 +324,7 @@ main(int argc, char **argv)
 	int pam_silent = PAM_SILENT;
 #endif
 
-	parseconfig("/usr/local/etc/doas.conf", 1);
+	parseconfig(DOAS_CONF, 1);
 
 	/* cmdline is used only for logging, no need to abort on truncate */
 	(void) strlcpy(cmdline, argv[0], sizeof(cmdline));
